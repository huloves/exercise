#include <stdio.h>

int n, m, p, q, min = 99999999;
int a[51][51], book[51][51];

void dfs(int x, int y, int step)
{
    int next[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}};
    int tx, ty, k;
    //判断是否到达小哈的位置
    if(x == p && y == q) {
        //更新最小值
        if(step < min) {
            min = step;
        }
        return;
    }

    //枚举4种走法
    for(k=0; k<4; k++) {
        //计算下一个点的坐标
        tx = x + next[k][0];
        ty = y + next[k][1];
        //判断是否越界
        if(tx<1 || tx>n || ty<1 || ty>m) {
            continue;
        }
        //判断该点是否为障碍物或者已经在路径中
        if(a[tx][ty] == 0 && book[tx][ty] == 0) {
            book[tx][ty] = 1;
            dfs(tx, ty, step + 1);
            book[tx][ty] = 0;
        }
    }
    return;
}

int main()
{
    int i, j, startx, starty;
    //读入n和m，n为行，m为列
    scanf("%d %d", &n, &m);
    //读入迷宫
    for(i=1; i<=n; i++) {
        for(j=1; j<=m; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    //读入起点和重点坐标
    scanf("%d %d %d %d", &startx, &starty, &p, &q);

    //从起点开始搜索
    book[startx][starty] = 1;
    dfs(startx, starty, 0);

    printf("min = %d\n", min);

    return 0;
}
