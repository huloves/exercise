#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	if(argc < 4) {
		printf("Usage: ./a.out [number number number]\n");
		exit(1);
	}
	int a, b, c;
	a = atoi(argv[1]);
	b = atoi(argv[2]);
	c = atoi(argv[3]);
	if( (a == b) && (a == c) ) {
		printf("equal\n");
	} else {
		printf("not equal\n");
	}
	return 0;
}
