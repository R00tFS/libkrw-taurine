//Kernel RW API for Taurine

// Falls back to HSP4 -> TFP0 automatically if Taurine's kernRW not available

#include <mach/kern_return.h>

int requestKernRw(void);

kern_return_t libkernrw_read32(uint64_t addr, uint32_t *val);
kern_return_t libkernrw_read64(uint64_t addr, uint64_t *val);
kern_return_t libkernrw_write32(uint64_t addr, uint32_t val);
kern_return_t libkernrw_write64(uint64_t addr, uint64_t val);

kern_return_t libkernrw_readbuf(uint64_t addr, void *buf, size_t len);
kern_return_t libkernrw_writebuf(uint64_t addr, const void *buf, size_t len);

kern_return_t libkernrw_getKernelBase(uint64_t *val);

kern_return_t libkernrw_getKernelProc(uint64_t *val);
