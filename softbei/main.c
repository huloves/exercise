#include "signation.h"
#include <stdio.h>
#include <stdlib.h>
#include <elf.h>

int main(const int argc, const char* argv[])
{
    int file_size;   //记录原始ELF文件大小
    void* file_start;   //缓冲区，用于存储elf_header and section_header
    uint64_t ELF64_shoff;   //64位系统的section_header的偏移量
    const char* signation;   //签名字符串
    //判断参数
    option_test(argc, argv);
    //获取文件大小
    file_size = get_file_size(argv[1]);
    //缓冲区分配空间
    file_start = (uint8_t*)malloc(sizeof(uint8_t) * file_size);
    //将文件读取到缓冲区中
    read_file(argv[1], file_start, file_size);
    for(int i=0; i<16; i++) {
        printf("%x ", *(uint8_t*)(file_start+i));
    }
    printf("\n");
    ELF64_shoff = *(uint64_t*)(file_start + 40);
    //在文件末尾添加签名
    signation = SIGNATION;
    add_section(argv[1], signation);
    return 0;
}
