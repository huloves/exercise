#include "signation.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define BUFFER_SIZE 1024

void my_error(const char* error_function, const int line)
{
    perror(error_function);
    printf("line:%d", line);
}

void option_test(const int argc, const char** argv)
{
    //只能有两个参数
    if(argc != 2) {
        printf("option error\n");
        printf("./signation elf_filename\n");
        exit(1);
    }

    //判断是否为elf格式的文件
    int fd;
    char elf_type[16] = {0x7f, 0x45, 0x4c, 0x46, 0x02, 0x01, 0x01, \
                        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
    char signation_file[14] = "had signation";
    char buffer[BUFFER_SIZE];

    fd = open(argv[1], O_RDONLY);
    read(fd, buffer, 16);
    if((strncmp(elf_type, buffer, 16))) {
        printf("the file is not elf_file\n");
        close(fd);
        exit(1);
    }
    //不可以重复签名，在文件末尾添加秘钥，检测秘钥是否已经存在（秘钥：had signation）
    lseek(fd, -13, SEEK_END);
    read(fd, buffer, 13);
    printf("buffer:%s\n", buffer);
    if(!(strncmp(signation_file, buffer, 13))) {
        printf("had signed\n");
        close(fd);
        exit(1);
    }
    close(fd);
}

int get_file_size(const char* filename)
{
    struct stat file_stat;
    stat(filename, &file_stat);
    return file_stat.st_size;
}

void read_file(const char* filename, void* dst, const int size)
{
    int fd = open(filename, O_RDONLY);
    if(fd == -1) {
        my_error("open", __LINE__-2);
        exit(1);
    }
    read(fd, dst, size);
    close(fd);
}

void write_file(const char* filename, const void* src, const int size)
{
    int fd = open(filename, O_WRONLY);
    if(fd == -1) {
        my_error("open", __LINE__-2);
        exit(1);
    }
    write(fd, src, size);
    close(fd);
}

void add_signation(const char* filename, const char* str)
{
    int fd;
    int len;
    if((fd = open(filename, O_RDWR)) == -1) {
        my_error("open", __LINE__-1);
    }
    len = strlen(str);
    lseek(fd, 0, SEEK_END);
    write(fd, str, len);
    close(fd);
}

void get_elf64_shdr(const void* shdr_start, Elf64_Shdr* section_header)
{
    section_header->sh_name = *(Elf64_Word*)(shdr_start + 0);
    section_header->sh_type = *(Elf64_Word*)(shdr_start + 4);
    section_header->sh_flags = *(Elf64_Xword*)(shdr_start + 8);
    section_header->sh_addr = *(Elf64_Addr*)(shdr_start + 16);
    section_header->sh_offset = *(Elf64_Off*)(shdr_start + 24);
    section_header->sh_size = *(Elf64_Xword*)(shdr_start + 32);
    section_header->sh_link = *(Elf64_Word*)(shdr_start + 40);
    section_header->sh_info = *(Elf64_Word*)(shdr_start + 44);
    section_header->sh_addralign = *(Elf64_Xword*)(shdr_start + 48);
    section_header->sh_entsize = *(Elf64_Xword*)(shdr_start + 56);
}

void print_elf64_shdr(const Elf64_Shdr section_header)
{
    printf("sh_name     |%d\n", section_header.sh_name);
    printf("sh_type     |%d\n", section_header.sh_type);
    printf("sh_flags    |%lx\n", section_header.sh_flags);
    printf("sh_addr     |%016lx\n", section_header.sh_addr);
    printf("sh_offset   |%08lx\n", section_header.sh_offset);
    printf("sh_size     |%016lx\n", section_header.sh_size);
    printf("sh_link     |%d\n", section_header.sh_link);
    printf("sh_info     |%d\n", section_header.sh_info);
    printf("sh_addralign|%ld\n", section_header.sh_addralign);
    printf("sh_entsize  |%016lx\n", section_header.sh_entsize);
}

void alter_elf64_shdr(const void* shdr_start, const Elf64_Shdr section_header)
{
    *(Elf64_Word*)(shdr_start + 0) = section_header.sh_name;
    *(Elf64_Word*)(shdr_start + 4) = section_header.sh_type;
    *(Elf64_Xword*)(shdr_start + 8) = section_header.sh_flags;
    *(Elf64_Addr*)(shdr_start + 16) = section_header.sh_addr;
    *(Elf64_Off*)(shdr_start + 24) = section_header.sh_offset;
    *(Elf64_Xword*)(shdr_start + 32) = section_header.sh_size;
    *(Elf64_Word*)(shdr_start + 40) = section_header.sh_link;
    *(Elf64_Word*)(shdr_start + 44) = section_header.sh_info;
    *(Elf64_Xword*)(shdr_start + 48) = section_header.sh_addralign;
    *(Elf64_Xword*)(shdr_start + 56) = section_header.sh_entsize;
}