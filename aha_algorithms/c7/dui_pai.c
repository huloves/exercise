#include <stdio.h>

int h[101];   // 存放堆的数组
int n;   // 堆的元素个数

// swap
void swap(int x, int y);
// 向下调整函数
void shiftdown(int i);
// 建立堆
void create();
// 删除最大的元素
int delete_min();

int main(int argc, char** argv)
{
    int i, num;
    scanf("%d", &num);
    for(i = 1; i <= num; i++) {
        scanf("%d", h[i]);
    }
    create();
    for(i = 1; i <= num; i++) {
        printf("%d ", delete_min());
    }
    printf("\n");
    return 0;
}

void swap(int x, int y) {
    int t = h[x];
    h[x] = h[y];
    h[y] = t;
    return;
}

void shiftdown(int i) {
    int flag = 0;
    int t;
    // 当i节点有儿子，并且有需要调整的时候循环
    while(i * 2 <= n &&  flag == 0) {
        // 首先判断和做左儿子的关系
        if(h[i] < h[i * 2]) {
            t = i;
        } else {
            t = h[i * 2];
        }
        // 先判断是否有右儿子
        if(i * 2 + 1 <= n) {
            if(h[t] > h[i * 2 + 1]) {
                t = i * 2  + 1;
            }
        }
        // 判断最小的节点是不是i，若不是，则进行交换
        if(i != t) {
            swap(i, t);
            i = t;   // 更新i为刚才与它交换的节点的编号，用于接下来继续向下调整
        } else {
            flag = 1;   //否则说明当前的父节点已经比两个子节点小，不需要再进行调整了
        }
    }
    return;
}

void create() {
    int i;
    // 从最后一个非叶节点开始依次向下调整
    for(int i = n / 2; i >= 1; i--) {
        shiftdown(i);
    }
    return;
}

int delete_min() {
    int t;
    t = h[1];
    h[1] = h[n];   // 将堆的最后一个点赋值到堆顶
    n--;
    shiftdown(1);
    return t;
}