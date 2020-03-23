#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define bool int
#define false 0
#define true  1

#define SIGNATION "test"
#define BUFFER_SIZE 1024

bool option_test(const int argc, const char** argv);
void add_signation(int elf_fd, char* signation);

void my_error(char* error_funtion, int line);

int main(int argc, const char* argv[])
{
    if(!option_test(argc, argv)) {
        return 0;
    }
    
    int fd = open(argv[1], O_RDONLY);
    if(fd == -1) {
        my_error("open", __LINE__);
    }
    char* signation = SIGNATION;
    add_signation(fd, signation);

    close(fd);
    return 0;
}

bool option_test(const int argc, const char** argv)
{
    if(argc != 2) {
        printf("option error\n");
        printf("./signation elf_filename");
        return false;
    }

    int fd = open(argv[1], O_RDONLY);

    char elf_type[16] = {0x7f, 0x45, 0x4c, 0x46, 0x02, 0x01, 0x01, \
                        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
    char buffer[1024];

    read(fd, buffer, 16);
    if((strncmp(elf_type, buffer, 16))) {
        printf("the file is not elf_file\n");
        close(fd);
        return false;
    }
    close(fd);
    return true;
}

void my_error(char* error_function, int line)
{
    perror(error_function);
    printf("line:%d", line);
}

void add_signation(int elf_fd, char* signation)
{
    int section_num;   //记录节头数量
    char buffer[BUFFER_SIZE];
    lseek(elf_fd, 60, SEEK_SET);   //文件指针移动到节头数量处
    read(elf_fd, buffer, 2);
    buffer[strlen(buffer)] = '\0';
    for(int i=0; i<2; i++) {
        printf("%c\n", buffer[i]);
    }
    printf("buffer:%s\n", buffer);
    printf("section number = %d\n", section_num);
}
