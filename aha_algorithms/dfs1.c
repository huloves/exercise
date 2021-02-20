#include <stdio.h>

int a[10], book[10], n;

void dfs(int step)
{
    int i;
    if(step == n+1) {   //如果站在n+1个盒子面前，则表示前n个盒子已经放好扑克牌
        //输出结果
        for(i=1; i<=n; i++) {
            printf("%d", a[i]);
        }
        printf("\n");
        return;
    }

    //站在第step个盒子面前，应该放哪张牌？
    //按照1、2、3...n的顺序一一尝试
    for(i=1; i<=n; i++) {
        //判断扑克牌i是否在手上
        if(book[i] == 0) {
            //开始尝试扑克牌i
            a[step] = i;
            book[i] = 1;

            //第step个盒子已经放好扑克牌，接下来需要走到下一个盒子面前
            dfs(step + 1);
            book[i] = 0;   //将刚才尝试的扑克牌收回，才能进行下一次尝试
        }
    }
    return;
}

int main()
{
    scanf("%d", &n);
    dfs(1);
    return 0;
}
