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
#include <unistd.h>

int kread_wrapper(uint64_t from, void* to, size_t len) {
    return (libkernrw_readbuf(from, to, len) == 0) ? 0 : EDEVERR;
}

int kwrite_wrapper(void *from, uint64_t to, size_t len) {
    return (libkernrw_writebuf(to, from, len) == 0) ? 0 : EDEVERR;
}

int kbase_wrapper(uint64_t *kbase) {
    return (libkernrw_getKernelBase(kbase) == 0) ? 0 : EDEVERR ;
}
                           
int kmalloc_wrapper(uint64_t *addr, size_t size) {
    return ENOTSUP;
}
                         
int kdealloc_wrapper(uint64_t addr, size_t size) {
    return ENOTSUP;
}

__attribute__((used, visibility("default"))) krw_plugin_initializer_t krw_initializer(krw_handlers_t handlers) {
    if (geteuid() != 0) return EPERM;
    
    int status = requestKernRw();
    
    if (status != 0) return EPERM;
    
    handlers->kbase = kbase_wrapper;
    handlers->kread = kread_wrapper;
    handlers->kwrite = kwrite_wrapper;
    handlers->kmalloc = kmalloc_wrapper;
    handlers->kdealloc = kdealloc_wrapper;
    return 0;
}
