#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmpfunc(const void *a, const void *b) {
	return *(int*)a - *(int*)b;
}

int main()
{
	int array[] = {3, 1, 5, 8, 4, 6, 5};
	qsort(array, sizeof(array) / sizeof(array[0]), sizeof(array[0]), cmpfunc);
	for(int i = 0; i < sizeof(array) / sizeof(array[0]); i++) {
		printf("%d ", array[i]);
	}
	printf("\n");
	return 0;
}
