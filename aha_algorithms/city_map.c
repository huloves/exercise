#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void dfs(int cur, int dis);

int n;
int e[101][101];
int min = 99999999;
int book[101] = {0};

int main(int argc, char** argv)
{
    int m;
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

    int a, b, c;
    for(int i = 1; i <= m; i++) {
        scanf("%d %d %d", &a, &b, &c);
        e[a][b] = c;
    }

    book[1] = 1;
    dfs(1, 0);    

    printf("%d\n", min);

    return 0;
}

void dfs(int cur, int dis) {
    if(dis > min) {
        return;
    }
    if(cur == n) {
        if(dis < min) {
            min = dis;
        }
        return;
    }

    for(int i = 1; i <= n; i++) {
        if(e[cur][i] != 0 && e[cur][i] != 99999999 && book[i] == 0) {
            // dis += e[cur][i];
            book[i] = 1;
            dfs(i, dis + e[cur][i]);
            // dfs(i, dis);
            // dis -= e[cur][i];
            book[i] = 0;
        }
    }

    return;
}