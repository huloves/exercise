#include <iostream>
#include <memory>
#include <string>
#include <list>
#include <vector>

using namespace std;

int main(int argc, char *argv)
{
	shared_ptr<string> p1;
	shared_ptr<list<int>> p2;
	if(p1 && p1->empty()) {
		*p1 = "hi";
	}
	shared_ptr<int> p3 = make_shared<int>(42);
	shared_ptr<string> p4 = make_shared<string>(10, '9');
	shared_ptr<int> p5 = make_shared<int>();   // 值初始化

	shared_ptr<int> r = make_shared<int>(42);

	return 0;
}
