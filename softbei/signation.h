#ifndef __SIGNATION_H
#define __SIGNATION_H
#include <stdbool.h>

typedef unsigned char uint8_t;
typedef unsigned long long int uint64_t;

#define SIGNATION "test"
#define EHSIZE 64
#define SHSIZE 64

void my_error(char* error_function, int line);
void option_test(int argc, char** argv);
void read_file_header(char* filename, void* dst);

#endif
