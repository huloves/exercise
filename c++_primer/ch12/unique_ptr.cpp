#include <iostream>
#include <memory>
#include <string>

using namespace std;

int main()
{
	// 定义 unique_ptr 时需要将其绑定到一个 new 返回的指针上，初始化 unique_ptr 必须采用直接初始化
	// unique_ptr<string> p1;
	unique_ptr<string> p2(new string("hello"));

	// 因为unique_ptr拥有它指向的对象，因此unique_ptr不支持不同的拷贝或赋值操作
	unique_ptr<string> p1(new string("Stegosaurus"));
	// unique_ptr<string> p2(p1);   // ❌ unique_ptr 不支持拷贝
	// unique_ptr<string> p3;
	// p3 = p2;   // ❌ unique_ptr不支持赋值
	unique_ptr<string> p2(p1.release());
	unique_ptr<string> p3(new string("Trex"));
	p2.reset(p3.release());
	return 0;
}
