#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>

int main()
{
	int socket_fd;
	socket_fd = socket(AF_INET, SOCK_STREAM, 0);
	if(socket_fd == 0) {
		perror("socket");
		exit(1);
	}

	struct sockaddr_in serv_addr;	
	memset(&serv_addr, 0, sizeof(struct sockaddr_in));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(8080);
	serv_addr.sin_addr.s_addr = inet_addr("10.211.55.6");

	if(connect(socket_fd, (struct sockaddr *)&serv_addr, sizeof(struct sockaddr_in)) < 0) {
		perror("connect");
		exit(1);
	}

	char recv_buf[1500];
	int len = 1500;
	if(recv(socket_fd, recv_buf, sizeof(recv_buf), 0) < 0) {
		perror("recv");
		exit(1);
	}
	printf("recv:%s\n", recv_buf);

	close(socket_fd);

	return 0;
}
