#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/time.h>
#include <unistd.h>
#include <time.h>

void display_time(const char *string) {
	int seconds;
	seconds = time((time_t*)NULL);
	printf("%s, %d\n", string, seconds);
}

int main()
{
	fd_set readfds;
	struct timeval timeout;
	int ret;

	FD_ZERO(&readfds);
	FD_SET(0, &readfds);

	timeout.tv_sec = 10;
	timeout.tv_usec = 0;

	while(1) {
		display_time("before select");
		ret = select(1, &readfds, NULL, NULL, &timeout);
		display_time("after select");

		switch(ret) {
			case 0:
				printf("No data in ten seconds.\n");
				exit(0);
				break;
			case -1:
				perror("select");
				exit(1);
				break;
			default:
				getchar();
				printf("Data is availiable now.\n");
		}
	}

	return 0;
}
