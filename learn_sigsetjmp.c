#include <stdio.h>
#include <signal.h>
#include <setjmp.h>
#include <unistd.h>
#include <setjmp.h>

sigjmp_buf jmp_env;

static void connect_alarm(int signo)
{
    siglongjmp(jmp_env, 1);
}

int main(int argc, char** argv)
{
    int sec_timeout = 3;
    int run_time = 4;

    printf("sec_timeout = %d, rum_time = %d\n", sec_timeout, run_time);
    if (sec_timeout) {   //sec_timeout = 3
        signal(SIGALRM, connect_alarm);
        alarm(sec_timeout);   //sec_timeout = 3
        printf("set timeout\n");
        if(sigsetjmp(jmp_env, 1)) {
            printf("timeout\n");
            goto out;
        }
    }

    sleep(run_time);
    printf("running...\n");

out:
    if(sec_timeout) {
        alarm(0);
        printf("cancel timeout\n");
    }
    
    return 0;
}
