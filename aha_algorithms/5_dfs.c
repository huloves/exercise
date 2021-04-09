#include <stdio.h>

int sum, n;
int e[101][101];
int book[101];

void dfs(int cur)
{
    printf("%d \n", cur);
    sum++;
    if(sum == n) {
        return;
    }
    for(int i = 1; i <= n; i++) {
        if(e[cur][i] == 1 && book[i] == 0) {
            book[i] = 1;
            dfs(i);   //从定点i再出发继续遍历
        }
    }
    return;
}

int main(int argc, char** argv)
{
    //初始化二为矩阵
    int m, a, b;
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
    
    //读入顶点之间的边
    for(int i = 1; i <= m; i++) {
        scanf("%d %d", &a, &b);
        e[a][b] = 1;
        e[b][a] = 1;
    }
    
    //从1号顶点出发
    book[1] = 1;
    dfs(1);

    return 0;
}