#include <elf.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

void error_exit(int exit_code, const char *message);
void check_elf(Elf64_Ehdr *header);
void print_elf_info(Elf64_Ehdr *header);
void close_file(int fd);

int main(int argc, char *argv[])
{
	int fd;
	Elf64_Ehdr header;

	if (argc != 2)

		error_exit(97, "Usage: elf_header file");

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		error_exit(98, "Error; Cant read file");

	if (read(fd, &header, sizeof(Elf64_Ehdr)) == -1)
	{
		close_file(fd);
		error_exit(98, "Error: Cant read file");
	}

	check_elf(&header);
	print_elf_info(&header);

	close_file(fd);
	return (0);
}

void error_exit(int exit_code, const char *message)
{
	dprintf(STDERR_FILENO, "%s\n", message);
	exit(exit_code);
}

void check_elf(Elf64_Ehdr *header)
{
	if (header->e_ident[EI_MAG0] != ELFMAG0 ||
	header->e_ident[EI_MAG1] != ELFMAG1 ||
	header->e_ident[EI_MAG2] != ELFMAG2 ||
	header->e_ident[EI_MAG3] != ELFMAG3)
	error_exit(98, "Error: Not an ELF file");
}

void print_elf_info(Elf64_Ehdr *header)
{
	int i;

	printf("ELF Header:\n");
	printf(" Magic: ");
	for (i = 0; i < EI_NIDENT; i++)
		printf("%02x%s", header->e_ident[i], i == EI_NIDENT - 1 ? "\n" : " ");
	printf(" Class: %s\n", header->e_ident[EI_CLASS] ==ELFCLASS32 ? "ELF32" : "ELF64");
	printf(" Data: %s\n", header->e_ident[EI_DATA] == ELFDATA2LSB ? "2's complement, little endian" :
			(header->e_ident[EI_DATA] == ELFDATA2MSB ? "2's complement, big endian" : "none"));

	printf(" Version: %d%s\n", header->e_ident[EI_VERSION], header->e_ident[EI_VERSION]== EV_CURRENT ? " (current)" : " ");
	printf(" OS/ABI: %d\n", header->e_ident[EI_OSABI]);
	printf(" ABI Version: %d\n", header->e_ident[EI_ABIVERSION]);
	printf(" Type: %d\n", header->e_type);
	printf(" Entry point address: %#lx\n", header->e_entry);
}

void close_file(int fd)
{
	if (close(fd) == -1)
		error_exit(100, "Error: Cant close file descriptor");
}
