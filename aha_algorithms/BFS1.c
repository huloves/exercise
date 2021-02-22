#include <stdio.h>

struct note
{
    int x;   //横坐标
    int y;   //纵坐标
    int f;   //父亲在队列中的编号
    int s;   //步数
};

int main(int argc, char** argv)
{
    struct note que[2501];

    int a[51][51] = {0}, book[51][51] = {0};
    //定义一个用于表示走的方向的数组
    int next[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}};
    int head, tail;
    int i, j, k, n, m, startx, starty, p, q, tx, ty, flag;

    scanf("%d %d", &n, &m);
    for(i = 1; i <= n; i++) {
        for(j = 1; j <= m; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    scanf("%d %d %d %d", &startx, &starty, &p, &q);

    //队列初始化
    head = 1;
    tail = 1;
    //王队列中插入迷宫的入口坐标
    que[tail].x = startx;
    que[tail].y = starty;
    que[tail].f = 0;
    que[tail].s = 0;
    tail++;
    book[startx][starty] = 1;

    flag = 0;   //用来标记是否到达目标点，0表示暂时还没有到达，1表示到达
    //当队列不为空的时候循环
    while(head < tail) {
        //枚举4个方向
        for(k = 0; k < 4; k++) {
            tx = que[head].x + next[k][0];
            ty = que[head].y + next[k][1];
            //判断是否越界
            if(tx < 1 || tx > n || ty < 1 || ty > n) {
                continue;
            }
            //判断是否是障碍物或者已经在路径中
            if(a[tx][ty] == 0 && book[tx][ty] == 0) {
                book[tx][ty] = 1;
                que[tail].x = tx;
                que[tail].y = ty;
                que[tail].f = head;
                que[tail].s = que[head].s + 1;
                tail++;
            }
            //如果到目标点了，停止扩张，任务结束，退出循环
            if(tx == p && ty == q) {
                flag = 1;
                break;
            }
        }
        if(flag == 1) {
            break;
        }
        head++;   //当一个点扩展结束后，head++才能对后面的点再进行扩展
    }

    //打印队列中最后一个点（目标点）的步数
    printf("%d\n", que[tail-1].s);

    return 0;
}
