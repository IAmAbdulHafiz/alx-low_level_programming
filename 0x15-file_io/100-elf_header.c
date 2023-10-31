#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>
#include <string.h>
#include <errno.h>
#include "main.h"

/**
 * print_elf_header - Displays the ELF header information.
 * @header: A pointer to the ELF header structure.
 */
void print_elf_header(const Elf64_Ehdr *header);

int main(int argc, char *argv[]) {
    const char *elf_filename;
    int fd;
    Elf64_Ehdr elf_header;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s elf_filename\n", argv[0]);
        return 1;
    }

    elf_filename = argv[1];
    fd = open(elf_filename, O_RDONLY);

    if (fd == -1) {
        fprintf(stderr, "Error: Failed to open the file: %s\n", strerror(errno));
        return 98;
    }

    if (read(fd, &elf_header, sizeof(Elf64_Ehdr)) != sizeof(Elf64_Ehdr)) {
        fprintf(stderr, "Error: Failed to read ELF header from file: %s\n", strerror(errno));
        close(fd);
        return 98;
    }

    if (memcmp(elf_header.e_ident, ELFMAG, SELFMAG) != 0) {
        fprintf(stderr, "Error: Not a valid ELF file\n");
        close(fd);
        return 98;
    }

    print_elf_header(&elf_header);

    close(fd);
    return 0;
}

void print_elf_header(const Elf64_Ehdr *header) {
    int i;
    const char *class_str;
    const char *data_str;
    const char *os_abi;
    const char *type_str;

    printf("ELF Header:\n");
    printf("  Magic:   ");
    for (i = 0; i < EI_NIDENT; i++) {
        printf("%02x", header->e_ident[i]);
        if (i < EI_NIDENT - 1) {
            printf(" ");
        }
    }
    printf("\n");

    class_str = (header->e_ident[EI_CLASS] == ELFCLASS64) ? "ELF64" : "ELF32";
    data_str = (header->e_ident[EI_DATA] == ELFDATA2LSB) ? "2's complement, little endian" : "2's complement, big endian";

    printf("  Class:                             %s\n", class_str);
    printf("  Data:                              %s\n", data_str);
    printf("  Version:                           %d (current)\n", header->e_ident[EI_VERSION]);

    os_abi = (header->e_ident[EI_OSABI] == ELFOSABI_SYSV) ? "UNIX - System V" : "Other";
    printf("  OS/ABI:                            %s\n", os_abi);
    printf("  ABI Version:                       %d\n", header->e_ident[EI_ABIVERSION]);

    type_str = (header->e_type == ET_EXEC) ? "EXEC (Executable file)" : "Other";
    printf("  Type:                              %s\n", type_str);

    printf("  Entry point address:               0x%lx\n", header->e_entry);
}
