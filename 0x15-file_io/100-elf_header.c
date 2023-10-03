/*
 * File: 100-elf_header.c
 * Auth: Abdul-Hafiz Yussif
 */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <elf.h>
#include <string.h>

/**
 * print_error_and_exit - Print an error message and exit the program.
 * @message: The error message to print.
 */

void print_error_and_exit(const char *message)
{
	fprintf(stderr, "%s\n", message);
	exit(98);
}

void print_elf_header(const Elf64_Ehdr *header);

int main(int argc, char *argv[])
{
	char *filename;
	int fd;
	struct stat file_info;
	Elf64_Ehdr elf_header;
	ssize_t bytes_read;

	if (argc != 2)
	{
		print_error_and_exit("Usage: elf_header elf_filename");
	}

	filename = argv[1];
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		print_error_and_exit("Error: Unable to open file");
	}

	if (fstat(fd, &file_info) == -1)
	{
		close(fd);
		print_error_and_exit("Error: Unable to read file information");
	}
	if ((size_t)file_info.st_size < sizeof(Elf64_Ehdr))
	{
		close(fd);
		print_error_and_exit("Error: File is too small to be an ELF file");
	}

	bytes_read = read(fd, &elf_header, sizeof(Elf64_Ehdr));
	if (bytes_read != sizeof(Elf64_Ehdr) || memcmp(elf_header.e_ident, ELFMAG,
				SELFMAG) != 0)
	{
		close(fd);
		print_error_and_exit("Error: Not an ELF file");
	}

	print_elf_header(&elf_header);

	close(fd);
	return (0);
}

/**
 * print_elf_header - Print the information from an ELF header.
 * @header: A pointer to the ELF header structure.
 */

void print_elf_header(const Elf64_Ehdr *header)
{
	int i;

	printf("ELF Header:\n");
	printf("Magic:   ");
	for (i = 0; i < EI_NIDENT; i++)
	{
		printf("%02x ", header->e_ident[i]);
	}
	printf("\n");
	printf("Class:    ");
	switch (header->e_ident[EI_CLASS])
	{
		case ELFCLASSNONE:
			printf("none\n");
			break;
		case ELFCLASS32:
			printf("ELF32\n");
			break;
		case ELFCLASS64:
			printf("ELF64\n");
			break;
		default:
			printf("<unknown: %x>\n", header->e_ident[EI_CLASS]);
	}
	printf("  Data:      ");
	switch (header->e_ident[EI_DATA])
	{
		case ELFDATANONE:
			printf("none\n");
			break;
		case ELFDATA2LSB:
			printf("2's complement, little endian\n");
			break;
		case ELFDATA2MSB:
			printf("2's complement, big endian\n");
			break;
		default:
			printf("<unknown: %x>\n", header->e_ident[EI_CLASS]);
	}
	printf("  Version:    %d", header->e_ident[EI_VERSION]);
	switch (header->e_ident[EI_VERSION])
	{
		case EV_CURRENT:
			printf(" (current)\n");
			break;
		default:
			printf("\n");
			break;
	}
	printf("  OS/ABI:                            ");
	switch (header->e_ident[EI_OSABI])
	{
		case ELFOSABI_NONE:
			printf("UNIX - System V\n");
			break;
		case ELFOSABI_HPUX:
			printf("UNIX - HP-UX\n");
			break;
		case ELFOSABI_NETBSD:
			printf("UNIX - NetBSD\n");
			break;
		case ELFOSABI_LINUX:
			printf("UNIX - Linux\n");
			break;
		case ELFOSABI_SOLARIS:
			printf("UNIX - Solaris\n");
			break;
		case ELFOSABI_IRIX:
			printf("UNIX - IRIX\n");
			break;
		case ELFOSABI_FREEBSD:
			printf("UNIX - FreeBSD\n");
			break;
		case ELFOSABI_TRU64:
			printf("UNIX - TRU64\n");
			break;
		case ELFOSABI_ARM:
			printf("ARM\n");
			break;
		case ELFOSABI_STANDALONE:
			printf("Standalone App\n");
			break;
		default:
			printf("<unknown: %x>\n", header->e_ident[EI_OSABI]);
	}
	printf("  ABI Version:   %d\n", header->e_ident[EI_ABIVERSION]);
	printf("  Type:                              ");
	if (header->e_ident[EI_DATA] == ELFDATA2MSB)
	{
		unsigned int e_type = header->e_type;
		e_type >>= 8;
		switch (e_type)
		{
			case ET_NONE:
				printf("NONE (None)\n");
				break;
			case ET_REL:
				printf("REL (Relocatable file)\n");
				break;
			case ET_EXEC:
				printf("EXEC (Executable file)\n");
				break;
			case ET_DYN:
				printf("DYN (Shared object file)\n");
				break;
			case ET_CORE:
				printf("CORE (Core file)\n");
				break;
			default:
				printf("Unknown\n");
				break;
		}
	}
	else
	{
		switch (header->e_type)
		{
			case ET_NONE:
				printf("NONE (None)\n");
				break;
			case ET_REL:
				printf("REL (Relocatable file)\n");
				break;
			case ET_EXEC:
				printf("EXEC (Executable file)\n");
				break;
			case ET_DYN:
				printf("DYN (Shared object file)\n");
				break;
			case ET_CORE:
				printf("CORE (Core file)\n");
				break;
			default:
				printf("Unknown\n");
				break;
		}
	}
	printf("  Entry point address:               ");
	if (header->e_ident[EI_DATA] == ELFDATA2MSB)
	{
		unsigned long int e_entry = header->e_entry;

		e_entry = ((e_entry << 8) & 0xFF00FF00) | ((e_entry >> 8) & 0xFF00FF);
		e_entry = (e_entry << 16) | (e_entry >> 16);
		printf("%#lx\n", e_entry);
	}
	else
	{
		if (header->e_ident[EI_CLASS] == ELFCLASS32)
			printf("%#x\n", (unsigned int)header->e_entry);
		else
			printf("%#lx\n", header->e_entry);
	}
}
