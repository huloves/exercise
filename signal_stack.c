#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

uint64_t* rsp;

void signal_handler(int signo)
{
    asm volatile ("movq %%rsp, %0" : : "m"(rsp));
    printf("rsp = %p\n", rsp);
    printf("*rsp = %ld\n", *rsp);
    
    if(signo == SIGINT) {
        signal(SIGINT, NULL);
    }
}

int main()
{
    signal(SIGINT, signal_handler);
    while(1);

    return 0;
}