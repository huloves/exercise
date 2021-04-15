#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv)
{
    int e[10][10], dis[10], book[10], i, j, n, m, t1, t2, t3, u, v, min;
    int inf = 99999999;

    scanf("%d %d", &n, &m);
    for(i = 1; i <= n; i++) {
        for(j = 1; j <= n; j++) {
            if(i == j) {
                e[i][j] = 0;
            } else {
                e[i][j] = inf;
            }
        }
    }

    for(i = 1; i <= m; i++) {
        scanf("%d %d %d", &t1, &t2, &t3);
        e[t1][t2] = t3;
    }

    //init dis[], 1号顶点到其余各个顶点的初试路程
    for(i = 1; i <= n; i++) {
        dis[i] = e[1][i];
    }

    //init book
    for(i = 1; i <= n; i++) {
        book[i] = 0;
    }
    book[1] = 1;

    //dijkstra core
    for(i = 1; i <= n-1; i++) {
        //找到离1号顶点最近的顶点
        min = inf;
        for(j = 1; j <= n; j++) {
            if(book[j] == 0 && dis[j] < min) {
                min = dis[j];
                u = j;
            }
        }
        book[u] = 1;   //将找到的距离1顶点最近的顶点加入P集合
        for(v = 1; v <= n; v++) {
            if(e[u][v] < inf) {
                if(dis[v] > dis[u] + e[u][v]) {
                    dis[v] = dis[u] + e[u][v];
                }
            }
        }
    }

    //print result
    for(i = 1; i <= n; i++) {
        printf("%d ", dis[i]);
    }
    printf("\n");

    return 0;
}