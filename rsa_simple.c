#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int hu_su(int a, int b);
int get_d_ok(int d, int e, int fai_n);

int main()
{
    int p, q, n, fai_n;

    printf("input p and q: ");
    scanf("%d %d", &p, &q);
    n = p * q;
    printf("p = %d, q = %d, n = %d\n", p , q, n);
    
    fai_n = (p - 1) * (q - 1);
    printf("fai_n = %d\n", fai_n);

    int e = fai_n - 1;
    // e = 7;
    while(!hu_su(e, fai_n)){
        e = e - 1;
    }

    printf("public key is PU{%d, %d}\n", e, n);

    int d = fai_n - 1;
    while(!get_d_ok(d, e, fai_n)) {
        d = d - 1;
    }

    printf("private key is PR{%d, %d}\n", d, n);

    printf("input number to encryption: ");
    int m;
    scanf("%d", &m);

    long long c;
    c = m;
    // c = pow(m * 1.0, d * 1.0);
    for(int i = 0; i < e - 1; i++) {
        c = m * c;
    }
    c = c % n;
    printf("c = %lld\n", c);
    
    printf("------ 解码 ------\n");

    long long M;
    M = c;
    for(int i = 0; i < d - 1; i++) {
        M = M * c; 
    }
    M = M % n;
    printf("M = %lld\n", M);

    return 0;
}

int hu_su(int a, int b)
{
    int min = a;
    int flag = 1;
    if(min > b) {
        min = b;
    }
    for(int i = 2; i <= min; i++) {
        if((a % i == 0) && (b % i == 0)) {
            flag = 0;
            break;
        }
    }
    return flag;
}

int get_d_ok(int d, int e, int fai_n)
{
    int flag = 1;
    if( ((d * e) % fai_n) != 1 ) {
        flag = 0;
    }
    return flag;
}
