#include <stdio.h>

int main()
{
    int book[1001], n, temp;
    for(int i=0; i<=1000; i++) {
        book[i] = 0;
    }

    scanf("%d", &n);

    for(int i=0; i<n; i++) {
        scanf("%d", &temp);
        book[temp]++;
    }

    for(int i=1000; i>=0; i--) {
        for(int j=0; j<book[i]; j++) {
            printf("%d ", i);
        }
    }

    printf("\n");

    return 0;
}