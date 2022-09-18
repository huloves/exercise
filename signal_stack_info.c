#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>

int i, j, k = 0;
unsigned char* stack_buffer;
unsigned long* p;
// uint64_t* rsp;

void sig_start(int signo)
{
    unsigned long a = 0x1234567811223344;

    // p = (unsigned char*)&a;
    stack_buffer = (unsigned char*)&a;

    printf("----begin stack----\n");
    for(i=0; i<32; i++) {
        for(j=0; j<8; j++) {
            printf(" %0.2x", stack_buffer[k]);
            k++;
        }
        printf("\n");
    }
    printf("----end stack----\n");

    printf("&a = 0x%llx\n", &a);
    printf("signo = %llx\n", signo);
    printf("&signo = %llx\n", &signo);

    k = 0;
    for(i=0; i<32; i++) {
        for(j=0; j<8; j++) {
            printf(" %0.2x", stack_buffer[k]);
            k++;
        }
        printf("\n");
    }
    printf("---------------------\n");

    if(signo = SIGINT) {
        signal(SIGINT, NULL);
    }
    if(signo = SIGHUP) {
        signal(SIGHUP, NULL);
    }
}

int main(int argc, char** argv)
{
    printf("process id is %d  %p %p\n", getpid(), main, sig_start);
    
    signal(SIGINT, sig_start);
    signal(SIGHUP, sig_start);

    while(1) {
        printf("AAAAAAAA|n");
        sleep(1);
    }

    return 0;
}
