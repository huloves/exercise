#include <stdio.h>
#include <stdlib.h>

char** pre_table;

char VT[] = {'+', '(', ')', '*', 'a', 'b'};
char VN[] = {'E', 'T', 'F', 'P'};

int main(int argc, char** argv)
{
    pre_table = (char**)malloc(sizeof(char*) * sizeof(VT));
    for(int i=0; i<sizeof(VT); i++) {
        *(pre_table+i) = (char*)malloc(sizeof(char*) * sizeof(VN));
    }


    for(int i=0; i<sizeof(VT); i++) {
        free(*(pre_table+i));
    }
    free(pre_table);

    return 0;
}