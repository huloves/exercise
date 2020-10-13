#include <stdio.h>

int main()
{
    int a[4], total = 0, book[10], sum;

    for(a[0]=0; a[0]<10; a[0]++) {
        for(a[1]=0; a[1]<10; a[1]++) {
            for(a[2]=0; a[2]<10; a[2]++) {
                for(a[3]=0; a[3]<10; a[3]++) {
                    printf("%d + %d == %d%d\n", a[0], a[1], a[2], a[3]);
                    for(int i=0; i<4; i++) {
                        book[i] = 0;
                    }
                    for(int i=0; i<4; i++) {
                        book[a[i]] = 1;
                    }
                    sum = 0;
                    for(int i=0; i<4; i++) {
                        sum += book[i];
                    }
                    if(sum == 4 && (a[0] + a[1]) == (a[2] * 10 + a[3])) {
                        total++;
                        printf("%d + %d == %d%d\n", a[0], a[1], a[2], a[3]);
                    }
                }
            }
        }
    }
    printf("total = %d\n", total / 2);
}
