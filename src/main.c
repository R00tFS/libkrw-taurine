//
//  main.c
//  libkrw-libkernrw
//
//  Created by rootfs on 06/06/2024.
//

#include <libkrw_plugin.h>
#include <libkernrw.h>
#include <errno.h>
#include <mach/kern_return.h>

int kread_wrapper(uint64_t from, void* to, size_t len) {
    return kernRW_readbuf(from, to, len);
}

int kwrite_wrapper(void *from, uint64_t to, size_t len) {
    return kernRW_writebuf(to, from, len);
}

int kbase_wrapper(uint64_t *kbase) {
    return kernRW_getKernelBase(kbase);
}
                           
int kmalloc_wrapper(uint64_t *addr, size_t size) {
    return ENOTSUP;
}
                         
int kdealloc_wrapper(uint64_t addr, size_t size) {
    return ENOTSUP;
}

int kcall_wrapper(uint64_t func, size_t argc, const uint64_t *argv, uint64_t *ret) {
    return ENOTSUP;
}

int physread_wrapper(uint64_t from, void *to, size_t len, uint8_t granule) {
    return ENOTSUP;
}

int physwrite_wrapper(void *from, uint64_t to, size_t len, uint8_t granule) {
    return ENOTSUP;
}

__attribute__((used)) krw_plugin_initializer_t krw_initializer(krw_handlers_t handlers) {
    requestKernRw();
    
    handlers->kbase = kbase_wrapper;
    handlers->kread = kread_wrapper;
    handlers->kwrite = kwrite_wrapper;
    handlers->kmalloc = kmalloc_wrapper;
    handlers->kdealloc = kdealloc_wrapper;
    return 0;
}

__attribute__((used)) krw_plugin_initializer_t kcall_initializer(krw_handlers_t handlers) {
    
    handlers->kcall = kcall_wrapper;
    handlers->physread = physread_wrapper;
    handlers->physwrite = physwrite_wrapper;

    return 0;
}
