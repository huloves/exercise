#include <algorithm>
#include <numeric>
#include <iostream>
#include <vector>
#include <string>
#include <deque>
#include <list>
#include <forward_list>
#include <iterator>

using namespace std;

int main(int argc, char *argv[])
{
	vector<int> ivec{2,2,2,5,4,6,7};
	list<string> str_list{"123", "123", "asdf", "sdf"};
	// auto tmp = count(ivec.cbegin(), ivec.cend(), 2);
	auto tmp = count(str_list.cbegin(), str_list.cend(), "123");
	vector<int>::value_type sum = accumulate(ivec.cbegin(), ivec.cend(), 0);
	cout << sum << endl;
	return 0;
}
