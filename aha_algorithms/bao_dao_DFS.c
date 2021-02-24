#include <stdio.h>

int a[51][51];
int book[51][51];
int n, m;
int sum = 0;

void dfs(int x, int y, int color)
{
    //定义方向数组
    int next[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}};

    //对a[x][y]进行染色
    a[x][y] = color;

    //枚举4个方向
    for(int i=0; i<4; i++) {
        //计算下一步的坐标
        int tx = x + next[i][0];
        int ty = y + next[i][1];
        
        //判断是否越界
        if(tx < 1 || tx > n || ty < 1 || ty > m) {
            continue;
        }

        //判断是否是陆地
        if(a[tx][ty] > 0 && book[tx][ty] == 0) {
            sum++;
            book[tx][ty] = 1;
            dfs(tx, ty, color);            
        }
    }
    return;
}

int main(int argc, char** argv)
{
    int startx, starty;
    scanf("%d %d %d %d", &n, &m, &startx, &starty);
    
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    book[startx][starty] = 1;
    sum = 1;
    dfs(startx, starty, -1);

    //输出染色后的地图
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            printf("%3d", a[i][j]);
        }
        printf("\n");
    }

    printf("sum = %d\n", sum);

    return 0;
}
