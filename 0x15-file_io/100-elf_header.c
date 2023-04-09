#include "main.h"
/**
 *
 * e_ident[] - IDENTIFICATION INDEXES
 *
 * Description: The initial bytes mark the file as an object file
 *              and provide machine-independent data.
 * The initial bytes of an ELF header (and an object file)
 *  correspond to the e_ident member.
*/

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: elf_header elf_filename\n");
        exit(98);
    }

    int fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        fprintf(stderr, "Error: Cannot open file %s\n", argv[1]);
        exit(98);
    }

    Elf64_Ehdr header;
    ssize_t bytes_read = read(fd, &header, sizeof(header));
    if (bytes_read < (ssize_t) sizeof(header)) {
        fprintf(stderr, "Error: Cannot read ELF header from file %s\n", argv[1]);
        exit(98);
    }

    // Check that the file is an ELF file
    if (header.e_ident[EI_MAG0] != ELFMAG0 ||
        header.e_ident[EI_MAG1] != ELFMAG1 ||
        header.e_ident[EI_MAG2] != ELFMAG2 ||
        header.e_ident[EI_MAG3] != ELFMAG3) {
        fprintf(stderr, "Error: File %s is not an ELF file\n", argv[1]);
        exit(98);
    }

    // Print the required information
    printf("Magic:   %02x %02x %02x %02x\n",
           header.e_ident[EI_MAG0], header.e_ident[EI_MAG1],
           header.e_ident[EI_MAG2], header.e_ident[EI_MAG3]);
    printf("Class:                             %s\n",
           header.e_ident[EI_CLASS] == ELFCLASS32 ? "ELF32" :
           header.e_ident[EI_CLASS] == ELFCLASS64 ? "ELF64" :
           "Unknown");
    printf("Data:                              %s\n",
           header.e_ident[EI_DATA] == ELFDATA2LSB ? "2's complement, little endian" :
           header.e_ident[EI_DATA] == ELFDATA2MSB ? "2's complement, big endian" :
           "Unknown");
    printf("Version:                           %d%s\n",
           header.e_ident[EI_VERSION],
           header.e_ident[EI_VERSION] == EV_CURRENT ? " (current)" : "");
    printf("OS/ABI:                            %s\n",
           header.e_ident[EI_OSABI] == ELFOSABI_SYSV ? "UNIX System V ABI" :
           header.e_ident[EI_OSABI] == ELFOSABI_LINUX ? "Linux ABI" :
           header.e_ident[EI_OSABI] == ELFOSABI_SOLARIS ? "Solaris ABI" :
           "Unknown");
    printf("ABI Version:                       %d\n",
           header.e_ident[EI_ABIVERSION]);
    printf("Type:                              %s\n",
           header.e_type == ET_REL ? "REL (Relocatable file)" :
           header.e_type == ET_EXEC ? "EXEC (Executable file)" :
           header.e_type == ET_DYN ? "DYN (Shared object file)" :
           header.e_type == ET_CORE ? "CORE (Core file)" :
           "Unknown");
    printf("Entry point address:               %lx\n",
           (unsigned long) header.e_entry);
    printf("Start of program headers:          %ld (bytes into

