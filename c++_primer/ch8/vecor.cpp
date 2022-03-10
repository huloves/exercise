#include <vector>
#include <iostream>
#include <list>
#include <deque>

using namespace std;

bool find(vector<int>::iterator begin, vector<int>::iterator end, int target) {
	for(auto iter = begin; iter != end; iter++) {
		if(*iter == target) {
			return true;
		}
	}
	return false;
}

vector<int>::const_iterator find_(vector<int>::const_iterator begin, vector<int>::const_iterator end, int target) {
	vector<int>::const_iterator iter;
	for(iter = begin; iter != end; iter++) {
		if(*iter == target) {
			break;
		}
	}
	return iter;
}

int main()
{
	list<deque<int>> obj;
	vector<int> vec{2, 4, 5, 7, 0};
	int tmp = 0;
	for(vector<int>::iterator iter = vec.begin(); iter != vec.end(); iter++) {
		tmp++;
		if(*iter == 7) {
			break;
		}
	}
	cout << tmp << endl;
	if(find(vec.begin(), vec.end(), 4)) {
		cout << "find ok" << endl;
	} else {
		cout << "find false" << endl;
	}
	vector<int>::const_iterator iter = find_(vec.cbegin(), vec.cend(), 10);
	if(iter != vec.cend()) {
		cout << *iter << endl;
	} else {
		cout << "not find" << endl;
	}
	auto iter1 = vec.begin();
	auto iter2 = vec.end();
	while(iter1 < iter2) {
		cout << *iter1 << endl;
		iter1++;
	}
	return 0;
}
