#ifndef __MY_RECV_H
#define __MY_RECV_H

#define BUFSIZE 1024

int my_recv(int conn_fd, char *data_buf, int len);
void my_err(const char *err_string, int line);

#endif
