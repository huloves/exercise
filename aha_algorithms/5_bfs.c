#include <stdio.h>

int main()
{
    int n, m;
    int e[101][101];
    int book[101] = {0};

    scanf("%d %d", &n, &m);
    //初始化二维矩阵
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(i == j) {
                e[i][j] = 0;
            } else {
                e[i][j] = 99999999;
            }
        }
    }

    //读入顶点
    int a, b;
    for(int i = 1; i <= m; i++) {
        scanf("%d %d", &a, &b);
        e[a][b] = 1;
        e[b][a] = 1;
    }

    //队列初始化
    int head = 1;
    int tail = 1;
    int que[10001];

    //从1号顶点出发，将一号顶点加入队列
    que[tail] = 1;
    tail++;
    book[1] = 1;

    //当队列不为空的时候循环
    int cur;
    while(head < tail && tail <= n) {
        cur = que[head];
        for(int i = 1; i <= n; i++) {
            //判断从顶点cur到的顶点i有边，并且判断顶点i是否已经访问过
            if(e[cur][i] == 1 && book[i] == 0) {
                que[tail] = i;
                tail++;
                book[i] = 1;
            }
            //如果tail大于n，则表明所有顶点都已经访问过
            if(tail > n) {
                break;
            }
        }
        head++;
    }
    
    for(int i = 1; i < tail; i++) {
        printf("%d ", que[i]);
    }
    printf("\n");

    return 0;
}