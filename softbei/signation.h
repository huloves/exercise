#ifndef __SIGNATION_H
#define __SIGNATION_H
#include <stdbool.h>
#include <elf.h>

#define SIGNATION "test"
#define EH64_SIZE sizeof(Elf64_Ehdr)
#define SH64_SIZE sizeof(Elf64_Shdr)
#define PH64_SIZE sizeof(Elf64_Phdr)

void my_error(const char* error_function, const int line);   //错误处理函数
void option_test(const int argc, const char** argv);   //参数测试符合2个参数，并且输入文件为ELF格式的文件
int get_file_size(const char* filename);   //得到filename的大小，以字节为单位
void read_file(const char* filename, void* dst, const int size);   //读filename文件size个字节到dst起始的地方
void add_section(const char* filename, const char* str);   //在文件filename末尾添加节，节的内容为str

#endif
