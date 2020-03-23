#include "signation.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    uint8_t* file_start;
    //判断参数
    option_test(argc, argv);
    file_start = (uint8_t*)malloc(sizeof(uint8_t) * (EHSIZE + SHSIZE));
    //将文件头读取到缓冲区中
    read_file_header(argv[1], file_start);
    for(int i=0; i<16; i++) {
        printf("%x ", *(file_start+i));
    }
    printf("\n");
    return 0;
}
