#ifndef __KERNEL_DEFS_H_
#define __KERNEL_DEFS_H_

#include <dynamic_libs/fs_functions.h>
#include <dynamic_libs/os_types.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _bat_t
{
    u32 h;
    u32 l;
} bat_t;

typedef struct _bat_table_t
{
    bat_t bat[8];
} bat_table_t;

#ifdef __cplusplus
}
#endif

#endif // __KERNEL_DEFS_H_
