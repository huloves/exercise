#include <iostream>
#include <string>
#include <vector>
#include "Sales_data.h"
#include "Person.h"
#include "Screen.h"
// #include "Window_mgr.h"

using namespace std;

int main()
{
	Screen::pos ht = 24, wd = 80;
	Screen scr(ht, wd, ' ');
	Screen *p = &scr;
	char c = scr.get();
	c = p->get();
	return 0;
}
