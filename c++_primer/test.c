#include <stdio.h>

int test(int*, int*);

int main()
{
	int a = 1, b = 2;
	printf("%d\n", test(&a, &b));
	return 0;
}

int test(int *a, int *b) {
	return *a + *b;
}
