#include <stdio.h>
#include <stdbool.h>
#include <string.h>

char str[200];
int len, b[200], n;
bool f, vis[200];

void dfs(int st, int num)
{
    if(f) {
        return;
    }
    if(st == len) {
        f = true;
        for(int i=0; i<num; i++) {
            if(i) {
                printf(" %d", b[i]);
            } else {
                printf("%d", b[i]);
            }
        }
        printf("\n");
    }
    int x = str[st] - '0';
    if(!vis[x] && x <= n && x > 0) {
        vis[x] = true;
        b[num] = x;
        dfs(st + 1, num + 1);
        vis[x] = false;
    }
    x = 10 * x + str[st+1] - '0';
    if(!vis[x] && x <= n && x > 0) {
        vis[x] = true;
        b[num] = x;
        dfs(st + 2, num + 1);
        vis[x] = false;
    }
}

int main()
{
    scanf("%s", str);
    len = strlen(str);
    n = len <= 9 ? len : (len-9)/2+9;
    dfs(0, 0);
    return 0;
}

