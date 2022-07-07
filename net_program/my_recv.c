#define MY_RECV_C

#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "my_recv.h"

void my_err(const char *err_string, int line) {
	fprintf(stderr, "line:%d ", line);
	perror(err_string);
	exit(1);
}

/**
 * my_recv - 从套接字上读取一次数据（“以‘\n’为结束标志”）
 * @conn_fd:  从该连接套接字上接收数据
 * @data_buf: 读取到的数据保存在此缓冲区中
 * @len:      data_buf 所指向的空间长度**/
int my_recv(int conn_fd, char *data_buf, int len) {
	static char recv_buf[BUFSIZE];
	static char *pread;   // 指向下一次读取数据的位置
	static int len_remain = 0;   // 自定义缓冲区中剩余字节数
	int i;

	if(len_remain <= 0) {
		if((len_remain = recv(conn_fd, recv_buf, sizeof(recv_buf), 0)) < 0) {
			my_err("recv", __LINE__);
		} else if (len_remain == 0) {   // 目的计算极端的 socket 连接关闭
			return 0;
		}
		pread = recv_buf;   // 重新初始化 pread 指针
	}

	for(i = 0; *pread != '\n'; i++) {
		if(i > len) {
			return -1;
		}
		data_buf[i] = *pread++;
		len_remain--;
	}

	len_remain--;
	pread++;

	return i;
}
