#include <stdio.h>
#include <stdlib.h>

int main()
{
	const int a = 1;
	int *p = &a;
	*p = 2;
	printf("%d\n", a);
	return 0;
}
