#include <string.h>
#include "kernel_defs.h"
#include "kernel_functions.h"
#include "syscalls.h"

void SetupKernelCallback(void){
    KernelSetupSyscalls();
}
