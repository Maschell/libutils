#include <string.h>
#include <stdlib.h>

#include <utils/elf_abi.h>
#include <utils/elf_utils.h>


u32 elf_get_section(u8 *data, const char *name, u32 * size, u32 * addr, int fail_on_not_found) {
    Elf32_Ehdr *ehdr = (Elf32_Ehdr *) data;

    if (   !data
            || !IS_ELF (*ehdr)
            || (ehdr->e_type != ET_EXEC)
            || (ehdr->e_machine != EM_PPC)) {
        OSFatal("Invalid elf file");
    }

    Elf32_Shdr *shdr = (Elf32_Shdr *) (data + ehdr->e_shoff);
    int i;
    for(i = 0; i < ehdr->e_shnum; i++) {
        const char *section_name = ((const char*)data) + shdr[ehdr->e_shstrndx].sh_offset + shdr[i].sh_name;
        if(strcmp(section_name, name) == 0) {
            if(addr) {
                *addr = shdr[i].sh_addr;
            }
            if(size) {
                *size = shdr[i].sh_size;
            }
            return shdr[i].sh_offset;
        }
    }

    if(fail_on_not_found) {
        OSFatal((char*)name);
    }

    return 0;
}

bool elf_copy_section(u8 * elf_data, const char * section_name) {
    u32 section_addr = 0;
    u32 section_len = 0;
    u32 section_offset = elf_get_section(elf_data, section_name, &section_len, &section_addr, false);
    if(section_offset > 0) {
        u8 *main_section = elf_data + section_offset;
        memcpy((void*) section_addr,(void*) main_section, section_len);

        DCFlushRange((void*)section_addr, section_len);
        ICInvalidateRange((void*)section_addr, section_len);
        return true;
    }
    return false;
}

u32 elf_copy_common_sections(u8 * elf_data) {
    Elf32_Ehdr *ehdr = (Elf32_Ehdr *) elf_data;
    if (       !elf_data
               || !IS_ELF (*ehdr)
               || (ehdr->e_type != ET_EXEC)
               || (ehdr->e_machine != EM_PPC)) {
        return 0;
    }

    bool error = false;

    if(!elf_copy_section(elf_data, ".text")) {
        return 0;
    }

    elf_copy_section(elf_data, ".rodata");
    elf_copy_section(elf_data, ".data");
    elf_copy_section(elf_data, ".bss");

    return elf_get_entry_addr(elf_data);
}

u32 elf_get_entry_addr(u8 * elf_data) {
    Elf32_Ehdr *ehdr = (Elf32_Ehdr *) elf_data;
    if (       !elf_data
               || !IS_ELF (*ehdr)
               || (ehdr->e_type != ET_EXEC)
               || (ehdr->e_machine != EM_PPC)) {
        return 0;
    }
    u8 * source_addr = (u8 *) elf_data;
    return ehdr->e_entry;
}
