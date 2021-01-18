#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <ucontext.h>

void func1(void* arg)
{
    printf("1\n");
    printf("11\n");
    printf("111\n");
    printf("1111\n");
}

void context_test()
{
    char stack[1024 * 128];
    ucontext_t child, main;

    getcontext(&child);
    child.uc_stack.ss_sp = stack;
    child.uc_stack.ss_size = sizeof(stack);
    child.uc_stack.ss_flags = 0;
    child.uc_link = &main;

    makecontext(&child, (void*)func1, 0);
    swapcontext(&main, &child);
    printf("main\n");
}

int main(int argc, char** argv)
{
    ucontext_t context;

    // getcontext(&context);
    // printf("hello world!\n");
    // sleep(1);
    // setcontext(&context);

    context_test();

    return 0;
}
