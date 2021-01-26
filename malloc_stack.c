#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    uint8_t* stack_min_addr = (uint8_t*)malloc(1024 * 4);
    uint64_t* task_stack;
    task_stack = (uint64_t*)(stack_min_addr + 1024 * 4);
    printf("stack_min_addr = %p\n", stack_min_addr);
    printf("task_stack = %p\n", task_stack);
    return 0;
}
