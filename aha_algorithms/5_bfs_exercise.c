#include <stdio.h>

int main(int argc, char** argv)
{
    //初始化矩阵
    int n, m;
    int e[101][101];
    int book[101] = {0};
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(i == j) {
                e[i][j] = 0;
            } else {
                e[i][j] = 99999999;
            }
        }
    }

    int a, b;
    for(int i = 1; i <= m; i++) {
        scanf("%d %d", &a, &b);
        e[a][b] = 1;
        e[b][a] = 1;
    }

    //init queue
    int head = 1;
    int tail = 1;
    int que[10001];

    //从1号顶点出发，将1号顶点加入队列
    que[tail] = 1;
    tail++;
    book[1] = 1;

    //running when queue is not empty
    int cur;
    while(head < tail) {
        cur = que[head];
        for(int i = 1; i <= n; i++) {
            if(e[cur][i] == 1 && book[i] == 0) {
                que[tail] = i;
                book[i] = 1;
                tail++;
            }
            if(tail > n) {
                break;
            }
        }
        head++;
    }

    //输出结果
    for(int i = 1; i < tail; i++) {
        printf("%d ", que[i]);
    }
    printf("\n");

    return 0;
}