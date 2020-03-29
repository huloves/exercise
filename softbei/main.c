#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <elf.h>
#include "signation.h"

int main(const int argc, const char* argv[])
{
    int file_size;   //记录原始ELF文件大小
    void* file_start;   //缓冲区，用于存储elf_header and section_header
    uint64_t ELF64_shoff;   //64位系统的section_header的偏移量
    const char* signation;   //签名字符串
    Elf64_Shdr section_header;
    //判断参数，返回文件指针
    option_test(argc, argv);
    //读取第0个section_header
    read_elf64_shdr(argv[1], &section_header);
    //获取文件大小
    file_size = get_file_size(argv[1]);
    //缓冲区分配空间
    file_start = (uint8_t*)malloc(sizeof(uint8_t) * file_size);
    //将文件读取到缓冲区中
    read_file(argv[1], file_start, file_size);
    //获取section_header在文件中的偏移
    ELF64_shoff = *(uint64_t*)(file_start + 40);
    //在文件末尾添加签名
    signation = SIGNATION;
    add_signation(argv[1], signation);
    //获取一个section_header
    //get_elf64_shdr((void*)(file_start + ELF64_shoff) + 64, &section_header);
    //输出section_header
    //print_elf64_shdr(section_header);
    //构建signation的section_heade
    make_signation64_shdr(&section_header, (Elf64_Off)file_size, (Elf64_Xword)strlen(signation));
    //修改第0个section_header
    alter_elf64_shdr(file_start + ELF64_shoff + SH64_SIZE * 0, section_header);
    //将缓冲区内容太写入文件
    write_file(argv[1], file_start, file_size);
    return 0;
}
