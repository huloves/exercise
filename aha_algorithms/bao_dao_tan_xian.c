#include <stdio.h>

struct note
{
    int x;
    int y;
};

int main()
{
    struct note que[2501];
    int head, tail;
    int a[51][51];
    int book[51][51];
    int i, j, k, sum, max = 0, mx, my, n, m, startx, starty, tx, ty;
    int next[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}};
    scanf("%d %d %d %d", &n, &m, &startx, &starty);

    //读入地图
    for(i=1; i<=n; i++) {
        for(j=1; j<=m; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    //队列初始化
    head = tail = 1;
    //插入其实降落的坐标
    que[tail].x = startx;
    que[tail].y = starty;
    tail++;
    book[startx][starty] = 1;
    sum = 1;

    while(head < tail) {
        for(k = 0; k <= 3; k++) {
            tx = que[head].x + next[k][0];
            ty = que[head].y + next[k][1];

            //判断是否越界
            if(tx < 1 || tx > n || ty < 1 || ty > m) {
                continue;
            }

            //判断是否是陆地或者曾经走过
            if(a[tx][ty] > 0 && book[tx][ty] == 0) {
                sum++;
                book[tx][ty] = 1;
                que[tail].x = tx;
                que[tail].y = ty;
                tail++;
            }
        }
        head++;
    }

    printf("sum = %d\n", sum);

    return 0;
}
