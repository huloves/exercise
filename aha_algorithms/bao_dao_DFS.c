#include <stdio.h>

int a[51][51];
int book[51][51];
int n, m;
int sum = 0;

void dfs(int x, int y)
{
    //定义方向数组
    int next[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}};

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
            dfs(tx, ty);            
        }
    }
    return;
}

int main(int argc, char** argv)
{
    int startx, starty;
    scanf("%d %d %d %d", &n, &m, &startx, &starty);
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    
    dfs(startx, starty);

    printf("sum = %d\n", sum);

    return 0;
}
