#include "signation.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdbool.h>

#define BUFFER_SIZE 1024

void add_signation(int elf_fd, char* signation);

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
    char buffer[BUFFER_SIZE];

    fd = open(argv[1], O_RDONLY);
    read(fd, buffer, 16);
    if((strncmp(elf_type, buffer, 16))) {
        printf("the file is not elf_file\n");
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

void add_section(const char* filename, const char* str)
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