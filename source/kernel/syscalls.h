#ifndef __SYSCALLS_H_
#define __SYSCALLS_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "kernel_defs.h"

void KernelSetupSyscalls(void);

void SC0x25_KernelCopyData(u32 addr, u32 src, u32 len);
void SC0x36_KernelReadDBATs(bat_table_t * table);
void SC0x37_KernelWriteDBATs(bat_table_t * table);

uint32_t __attribute__ ((noinline)) kern_read(const void *addr);
void __attribute__ ((noinline)) kern_write(void *addr, uint32_t value);

#ifdef __cplusplus
}
#endif

#endif // __KERNEL_FUNCTIONS_H_
