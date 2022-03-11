#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

int main()
{
	vector<int> ivec = {1,1,2,3,5,56};
	ivec.resize(10);
	for(auto iter = ivec.cbegin(); iter != ivec.cend(); iter++) {
		cout << *iter << " ";
	}
	cout << endl;
	fill_n(ivec.begin(), ivec.size(), 0);
	for(auto iter = ivec.cbegin(); iter != ivec.cend(); iter++) {
		cout << *iter << " ";
	}
	cout << endl;
	return 0;
}
