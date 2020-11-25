#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/time.h>
#include <signal.h>
#include "set_ticker.h"

// int set_ticker(int n_msecs);

uint64_t ticks = 0;

void signal_headler(int signal_num)
{
	printf("ticks = %lld\n", ticks++);
}

int main()
{
	signal(SIGALRM, signal_headler);
	if(set_ticker(1) == -1) {
		perror("set_ticker");
	} else {
		while(1) {
			pause();
		}
	}
	return 0;
}

/*int set_ticker(int n_msecs)
{
    struct itimerval new_timeset;
    long n_sec, n_usecs;

    n_sec = n_msecs / 1000;
    n_usecs = (n_msecs % 1000) * 1000L;

    //剩下的时间，tv.sec = 秒，tv.usec = 微秒
    new_timeset.it_interval.tv_sec = n_sec;
    new_timeset.it_interval.tv_usec = n_usecs;

    //间隔时间
    new_timeset.it_value.tv_sec = n_sec;
    new_timeset.it_value.tv_usec = n_usecs;

    return setitimer(ITIMER_REAL, &new_timeset, NULL);
}
*/