#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int is_huiwen_str(char* str)
{
    int len = strlen(str);
    for(int i=0; i < len / 2; i++) {
        if(*(str + i) != *(str + len - i - 1)) {
            return 0;
        }
    }
    return 1;
}

int main(int argc, char** argv)
{
    char* str = "1";
    char* str1 = "\0";
    printf("%d\n", is_huiwen_str(str));
    printf("%d\n", strlen(str1));
    return 0;
}
