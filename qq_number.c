#include <stdio.h>

int main()
{
    char a[100] = {'6', '3', '1', '7', '5', '8', '9', '2', '4'};
    int head, tail;
    int temp;
    char ans[100] = {0};

    head = 0;
    int i=0;
    for(tail=0; a[tail+1] != '\0'; tail++);
    while(a[head] != '\0') {
        ans[i++] = a[head];
        a[tail+1] = a[head+1];
        head += 2;
        tail += 1;
    }

    printf("%s\n", ans);
}
