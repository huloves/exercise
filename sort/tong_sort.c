#include <stdio.h>

int main()
{
    int a[11];
    int i,j,t;

    for(i=0; i<=10; i++) {
        a[i] = 0;
    }

    for(i=1; i<=5; i++) {
        scanf("%d", &t);
        a[t]++;
    }

    for(i=0; i<=10; i++) {
        for(j=0; j<a[i]; j++) {
            printf("%d ", i);
        }
    }

    printf("\n");

    return 0;
}