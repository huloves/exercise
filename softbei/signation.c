#include "signation.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdbool.h>

#define SIGNATION "test"
#define BUFFER_SIZE 1024

void add_signation(int elf_fd, char* signation);

void my_error(char* error_function, int line)
{
    perror(error_function);
    printf("line:%d", line);
}

void option_test(int argc, char** argv)
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

void read_file_header(char* filename, void* dst)
{
    int fd = open(filename, O_RDONLY);
    if(fd == -1) {
        my_error("open", __LINE__-2);
        exit(1);
    }
    read(fd, dst, EHSIZE + SHSIZE);
    close(fd);
}
