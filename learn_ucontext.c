#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <ucontext.h>

int main(int argc, char** argv)
{
    ucontext_t context;

    getcontext(&context);
    puts("hello world!\n");
    sleep(1);
    setcontext(&context);

    return 0;
}
