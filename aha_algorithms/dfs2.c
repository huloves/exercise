#include <stdio.h>

int a[10], book[10], total = 0;

void dfs(int step)
{
    int i;
    //判断边界
    if(step == 10) {   //如果站在第10个盒子面前，则表示前9个盒子已经放好扑克牌
        //判断是否满足等式
        if(a[1]*100+a[2]*10+a[3]+a[4]*100+a[5]*10+a[6] == a[7]*100+a[8]*10+a[9]) {
            //如果满足，可行解+1，并打印这个解
            total++;
            printf("%d%d%d+%d%d%d=%d%d%d\n", a[1], a[2], a[3], a[4], a[5], a[6], a[7], a[8], a[9]);
        }
        return;
    }

    //站在第step个盒子面前，应该放哪张
    for(i = 1; i<=9; i++) {
        //判断扑克牌i是否在手上
        if(book[i] == 0) {
            //开始尝试使用扑克牌i
            a[step] = i;
            book[i] = 1;

            //第step个盒子已经放置好扑克牌，走到下一个盒子面前
            dfs(step + 1);
            //将刚才尝试的扑克牌回收，进行下一次尝试
            book[i] = 0;
        }
    }
    return;
}

int main()
{
    dfs(1);   //首先站在第一个盒子面前
    printf("total = %d\n", total);
    
    return 0;
}
