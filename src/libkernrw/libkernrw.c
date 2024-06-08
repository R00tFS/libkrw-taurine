#include <unistd.h>
#include <mach/mach.h>
#include <errno.h>
#include "krw_daemonUser.h"

#define KERNRW_EXPORT __attribute__ ((visibility ("default")))

extern kern_return_t mach_vm_read_overwrite(task_t task, mach_vm_address_t addr, mach_vm_size_t size, mach_vm_address_t data, mach_vm_size_t *outsize);
extern kern_return_t mach_vm_write(task_t task, mach_vm_address_t addr, mach_vm_address_t data, mach_msg_type_number_t dataCnt);

mach_port_t krwPort = MACH_PORT_NULL;

KERNRW_EXPORT int requestKernRw(void) {
    kern_return_t ret = host_get_special_port(mach_host_self(), HOST_LOCAL_NODE, 14, &krwPort);
    if (getuid() == 0 && ret == KERN_SUCCESS){
        if (MACH_PORT_VALID(krwPort)){
            return 0;
        }
    }
    krwPort = MACH_PORT_NULL;

    return EPERM;
}

KERNRW_EXPORT kern_return_t libkernrw_read32(uint64_t addr, uint32_t *val){
    if (MACH_PORT_VALID(krwPort)){
        return krw_read32(krwPort, addr, val);
    }

    return KERN_INVALID_NAME;
}

KERNRW_EXPORT kern_return_t libkernrw_read64(uint64_t addr, uint64_t *val){
    if (MACH_PORT_VALID(krwPort)){
        return krw_read64(krwPort, addr, val);
    }
    return KERN_INVALID_NAME;
}

KERNRW_EXPORT kern_return_t libkernrw_write32(uint64_t addr, uint32_t val){
    if (MACH_PORT_VALID(krwPort)){
        return krw_write32(krwPort, addr, val);
    }

    return KERN_INVALID_NAME;
}

KERNRW_EXPORT kern_return_t libkernrw_write64(uint64_t addr, uint64_t val){
    if (MACH_PORT_VALID(krwPort)){
        return krw_write64(krwPort, addr, val);
    }

    return KERN_INVALID_NAME;
}

#define KERNRW_CHUNK_SIZE64 sizeof(uint64_t)
#define KERNRW_CHUNK_SIZE32 sizeof(uint32_t)
#define TFP0_MAX_CHUNK_SIZE 0xFFF

KERNRW_EXPORT kern_return_t libkernrw_readbuf(uint64_t addr, void *buf, size_t len){
    if (addr + len < addr || (mach_vm_address_t)buf + len < (mach_vm_address_t)buf){
        return KERN_INVALID_ARGUMENT;
    }
    if (MACH_PORT_VALID(krwPort)){
        kern_return_t ret = KERN_SUCCESS;

        size_t remainder = len % KERNRW_CHUNK_SIZE64;
        if (remainder == 0)
            remainder = KERNRW_CHUNK_SIZE64;
        size_t tmpSz = len + (KERNRW_CHUNK_SIZE64 - remainder);
        if (len == 0)
            tmpSz = 0;

        uint64_t *dstBuf = (uint64_t *)buf;

        size_t alignedSize = (len & ~(KERNRW_CHUNK_SIZE64 - 1));
        for (int64_t i = 0; i < alignedSize; i += KERNRW_CHUNK_SIZE64){
            ret = krw_read64(krwPort, addr + i, &dstBuf[i / KERNRW_CHUNK_SIZE64]);
            if (ret){
                return ret;
            }
        }
        if (len > alignedSize){
            uint64_t r = 0;
            ret = krw_read64(krwPort, addr + alignedSize, &r);
            if (ret){
                return ret;
            }
            memcpy(((uint8_t*)buf)+alignedSize, &r, len-alignedSize);
        }
        return ret;
    }

    return KERN_INVALID_NAME;
}

KERNRW_EXPORT kern_return_t libkernrw_writebuf(uint64_t addr, const void *buf, size_t len){
    if (addr + len < addr || (mach_vm_address_t)buf + len < (mach_vm_address_t)buf){
        return KERN_INVALID_ARGUMENT;
    }
    if (MACH_PORT_VALID(krwPort)){
        kern_return_t ret = KERN_SUCCESS;

        size_t remainder = len & KERNRW_CHUNK_SIZE64;
        if (remainder == 0)
            remainder = KERNRW_CHUNK_SIZE64;
        size_t tmpSz = len + (KERNRW_CHUNK_SIZE64 - remainder);
        if (len == 0)
            tmpSz = 0;

        uint64_t *dstBuf = (uint64_t *)buf;
        size_t alignedSize = (len & ~(KERNRW_CHUNK_SIZE64 - 1));
        for (int64_t i = 0; i < alignedSize; i+= KERNRW_CHUNK_SIZE64){
            ret = krw_write64(krwPort, addr + i, dstBuf[i / KERNRW_CHUNK_SIZE64]);
            if (ret){
                return ret;
            }
        }
        if (len > alignedSize){
            size_t remainingSize = len - alignedSize;
            if (remainingSize > KERNRW_CHUNK_SIZE32){
                uint32_t val = 0;
                ret = krw_read32(krwPort, addr + alignedSize, &val);
                if (ret){
                    return ret;
                }
                memcpy(&val, ((uint8_t*)buf) + alignedSize, remainingSize);
                ret = krw_write32(krwPort, addr + alignedSize, val);
                if (ret){
                    return ret;
                }
            } else {
                uint64_t val = 0;
                ret = krw_read64(krwPort, addr + alignedSize, &val);
                if (ret){
                    return ret;
                }
                memcpy(&val, ((uint8_t*)buf) + alignedSize, remainingSize);
                ret = krw_write64(krwPort, addr + alignedSize, val);
                if (ret){
                    return ret;
                }
            }
        }
        return ret;

    }

    return KERN_INVALID_NAME;
}

KERNRW_EXPORT kern_return_t libkernrw_getKernelBase(uint64_t *val){
    if (MACH_PORT_VALID(krwPort)){
        return krw_kernelBase(krwPort, val);
    }
    return KERN_INVALID_NAME;
}
