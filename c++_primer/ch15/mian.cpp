#include <iostream>
#include <string>
#include "Quote.h"

int main(int argc, char *argv[])
{
	Quote basic("123", 3.0);
	// Bulk_quote bulk("123", 4.0);
	Quote item;
	Bulk_quote bulk;
	Quote *p = &item;
	p = &bulk;
	Quote &r = bulk;
	return 0;
}