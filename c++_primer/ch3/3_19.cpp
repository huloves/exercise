#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char** argv)
{
	vector<int> vec1(10, 42);
	vector<int> vec2{42, 42, 42, 42, 42, 42, 42, 42, 42, 42};
	vector<int> vec3;
	for(int i = 0; i < 10; i++) {
		vec3.push_back(42);
	}
	return 0;
}
