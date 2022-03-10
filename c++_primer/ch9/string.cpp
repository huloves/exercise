#include <string>
#include <iostream>

using namespace std;

int main()
{
	string s("hello world!!!!!");
	string s2 = s.substr(0, 5);
	string s3 = s.substr(6);   // s3 = world
	string s4 = s.substr(6, 11);
	string s5 = s.substr(12);   // error
	string name("r2d2");
	string numbers("0123456789");
	string::size_type pos = 0;
	while((pos = name.find_first_of(numbers, pos)) != string::npos) {
		cout << "found number at index: " << pos << " element is " << name[pos] << endl;
		pos++;
	}
	return 0;
}
