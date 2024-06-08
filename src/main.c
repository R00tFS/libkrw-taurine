//
//  main.c
//  libkrw-taurine
//
//  Created by rootfs on 06/06/2024.
//

#include <libkrw_plugin.h>
#include "libkernrw/libkernrw.h"
#include <errno.h>
#include <mach/kern_return.h>

int kread_wrapper(uint64_t from, void* to, size_t len) {
    return libkernrw_readbuf(from, to, len);
}

int kwrite_wrapper(void *from, uint64_t to, size_t len) {
    return libkernrw_writebuf(to, from, len);
}

int kbase_wrapper(uint64_t *kbase) {
    return libkernrw_getKernelBase(kbase);
}
                           
int kmalloc_wrapper(uint64_t *addr, size_t size) {
    return ENOTSUP;
}
                         
int kdealloc_wrapper(uint64_t addr, size_t size) {
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
