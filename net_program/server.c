#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define LISTEN_NUM 12
#define BUFFERSIZE 1500

int main()
{
	int sock_fd = socket(AF_INET, SOCK_STREAM, 0);
	
	struct sockaddr_in serv_addr;
	memset(&serv_addr, 0, sizeof(struct sockaddr_in));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(8080);
	serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	
	if(bind(sock_fd, (struct sockaddr*)&serv_addr, sizeof(struct sockaddr_in)) < 0) {
		perror("bind");
		exit(1);
	}

	if(listen(sock_fd, LISTEN_NUM) < 0) {
		perror("listen");
		exit(1);
	}

	int connect_fd;
	int connect_len;
	struct sockaddr_in connect_addr;
	memset(&connect_addr, 0, sizeof(struct sockaddr_in));

	connect_len = sizeof(struct sockaddr_in);
	connect_fd = accept(sock_fd, (struct sockaddr*)&connect_addr, &connect_len);
	if(connect_fd < 0) {
		perror("accept");
		exit(1);
	}

	char send_buf[BUFFERSIZE];
	sprintf(send_buf, "hello world.");
	int len = BUFFERSIZE;
	if(send(connect_fd, send_buf, len, 0) < 0) {
		perror("send");
		exit(1);
	}

	close(connect_fd);
	close(sock_fd);

	return 0;
}
