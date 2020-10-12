#include <stdio.h>

int main()
{
    int q[102] = {0, 6, 3, 1, 7, 5, 8, 9, 2, 4};
    int head = 1;
    int tail = 10;
    while(head < tail) {
        printf("%d ", q[head]);
        head++;
        q[tail] = q[head];
        tail++;
        head++;
    }
    printf("\n");
    return 0;
}
