#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void init_str(char** str, int numRows)
{
    for(int i=0; i<numRows; i++) {
        *(*(str+i) + 0) = '\0';
    }
}

int min(int a, int b)
{
    return a < b ? a : b;
}

int get_row(int char_num, int cycle)
{
    int x = char_num % cycle;
    return min(x, cycle - x);
}

char * convert(char * s, int numRows){
    char** row;
    int cycle = numRows * 2 - 2;   //获取周期
    char* ans;
    ans = (char*)malloc(sizeof(char) * 100000);
    *(ans + 0) = '\0';
    //分配行空间
    row = (char**)malloc(sizeof(char*) * numRows);
    //为每一行分配空间
    for(int i=0; i<numRows; i++) {
        *(row + i) = (char*)malloc(sizeof(char) * 1000);
    }
    //初始化每行的字符串
    init_str(row, numRows);
    //处理字符串
    for(int i=0; i<strlen(s); i++) {
        //求该字符应在的行数
        int row_num = get_row(i, cycle);
        // printf("row_num = %d\n", row_num);
        //将字符加在相应行的尾部
        int len = strlen(*(row + row_num));
        // printf("len = %d %c\n", len, *(s+i));
        // printf("%c\n", *(*(row + row_num) + len));
        *(*(row + row_num) + len) = *(s + i);
        *(*(row + row_num) + len + 1) = '\0';
    }
    //连接每一行的字符
    for(int i=0; i<numRows; i++) {
        strcat(ans, *(row+i));
    }
    //输出结果
    printf("%d\n", strlen(ans));
    //释放空间
    for(int i=0; i<numRows; i++) {
        free(*(row + i));
    }
    free(row);
    return ans;
}

int main(int argc, char** argv)
{
    char* str = "A";
    int row_nums = 1;

    char* ans = convert(str, row_nums);
    printf("%s\n", ans);
    
    return 0;
}
