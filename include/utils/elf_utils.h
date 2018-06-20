#ifndef __ELF_UTILS_H_
#define __ELF_UTILS_H_


#ifdef __cplusplus
extern "C" {
#endif

#include <coreinit/debug.h>
#include <coreinit/cache.h>

unsigned int elf_get_section(unsigned char *data, const char *name, unsigned int * size, unsigned int * addr, int fail_on_not_found);

BOOL elf_copy_section(unsigned char * elf_data, const char * section_name, BOOL errorOnFailure);

uint32_t elf_copy_common_sections(unsigned char * elf_data);

uint32_t elf_get_entry_addr(unsigned char * elf_data);

#ifdef __cplusplus
}
#endif

#endif // __ELF_UTILS_H_
