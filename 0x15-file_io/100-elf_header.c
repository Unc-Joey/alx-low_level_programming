#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <elf.h>

/**
 * error_exit - Prints an error message to stderr and exits with a specified code.
 * @code: The exit code.
 * @message: The error message.
 */
void error_exit(int code, const char *message)
{
    dprintf(2, "%s\n", message);
    exit(code);
}

/**
 * print_magic - Prints the ELF magic numbers.
 * @e_ident: ELF identification array.
 */
void print_magic(unsigned char *e_ident)
{
    int i;

    printf("  Magic:   ");
    for (i = 0; i < EI_NIDENT; ++i)
        printf("%02x%c", e_ident[i], i == EI_NIDENT - 1 ? '\n' : ' ');
}

/**
 * print_class - Prints the ELF class.
 * @e_ident: ELF identification array.
 */
void print_class(unsigned char *e_ident)
{
    printf("  Class:                             ");
    switch (e_ident[EI_CLASS])
    {
    case ELFCLASS32:
        printf("ELF32\n");
        break;
    case ELFCLASS64:
        printf("ELF64\n");
        break;
    default:
        printf("<unknown: %x>\n", e_ident[EI_CLASS]);
    }
}

/**
 * print_data - Prints the ELF data encoding.
 * @e_ident: ELF identification array.
 */
void print_data(unsigned char *e_ident)
{
    printf("  Data:                              ");
    switch (e_ident[EI_DATA])
    {
    case ELFDATA2LSB:
        printf("2's complement, little endian\n");
        break;
    case ELFDATA2MSB:
        printf("2's complement, big endian\n");
        break;
    default:
        printf("<unknown: %x>\n", e_ident[EI_DATA]);
    }
}

/**
 * print_version - Prints the ELF version.
 * @e_ident: ELF identification array.
 */
void print_version(unsigned char *e_ident)
{
    printf("  Version:                           %d (current)\n", e_ident[EI_VERSION]);
}

/**
 * print_osabi - Prints the ELF OS/ABI.
 * @e_ident: ELF identification array.
 */
void print_osabi(unsigned char *e_ident)
{
    printf("  OS/ABI:                            ");
    switch (e_ident[EI_OSABI])
    {
    case ELFOSABI_SYSV:
        printf("UNIX - System V\n");
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
    default:
        printf("<unknown: %x>\n", e_ident[EI_OSABI]);
    }
}

/**
 * print_abiversion - Prints the ELF ABI version.
 * @e_ident: ELF identification array.
 */
void print_abiversion(unsigned char *e_ident)
{
    printf("  ABI Version:                       %d\n", e_ident[EI_ABIVERSION]);
}

/**
 * print_type - Prints the ELF type.
 * @e_type: ELF type.
 */
void print_type(unsigned int e_type)
{
    printf("  Type:                              ");
    switch (e_type)
    {
    case ET_EXEC:
        printf("EXEC (Executable file)\n");
        break;
    case ET_DYN:
        printf("DYN (Shared object file)\n");
        break;
    default:
        printf("<unknown: %x>\n", e_type);
    }
}

/**
 * print_entry - Prints the ELF entry point address.
 * @e_entry: ELF entry point address.
 */
void print_entry(Elf64_Addr e_entry)
{
    printf("  Entry point address:               0x%lx\n", (unsigned long)e_entry);
}

/**
 * read_elf_header - Reads the ELF header from a file and prints the information.
 * @filename: The name of the ELF file.
 */
void read_elf_header(const char *filename)
{
    int fd;
    Elf64_Ehdr header;

    fd = open(filename, O_RDONLY);
    if (fd == -1)
        error_exit(98, "Error: Couldn't open file");

    if (read(fd, &header, sizeof(header)) != sizeof(header))
        error_exit(98, "Error: Couldn't read ELF header");

    if (header.e_ident[EI_MAG0] != ELFMAG0 ||
        header.e_ident[EI_MAG1] != ELFMAG1 ||
        header.e_ident[EI_MAG2] != ELFMAG2 ||
        header.e_ident[EI_MAG3] != ELFMAG3)
        error_exit(98, "Error: Not an ELF file");

    printf("ELF Header:\n");
    print_magic(header.e_ident);
    print_class(header.e_ident);
    print_data(header.e_ident);
    print_version(header.e_ident);
    print_osabi(header.e_ident);
    print_abiversion(header.e_ident);
    print_type(header.e_type);
    print_entry(header.e_entry);

    if (close(fd) == -1)
        error_exit(100, "Error: Can't close fd");
}

/**
 * main - Entry point of the program.
 * @argc: The number of arguments.
 * @argv: The array of arguments.
 *
 * Return: 0 on success.
 */
int main(int argc, char *argv[])
{
    if (argc != 2)
        error_exit(97, "Usage: elf_header elf_filename");

    read_elf_header(argv[1]);

    return (0);
}

