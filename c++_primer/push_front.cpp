#include <iostream>
#include <list>
#include <vector>
#include "./sales_data.h"

using namespace std;

int main()
{
	list<int> ilist;
	for(size_t ix = 0; ix != 4; ix++) {
		ilist.push_front(ix);
	}
	cout << ilist.size() << endl;
	
	list<string> slist;
	list<string>::iterator iter_ = slist.begin();
	// auto iter_ = slist.begin();
	iter_ = slist.insert(iter_, "Hello!");
	cout << *(slist.begin()) << endl;
	cout << *iter_ <<  " 3333333" << endl;

	vector<string> svec;
	svec.insert(svec.end(), 10, "Anna");
	vector<string> v = {"quasi", "simba", "frollo", "scar"};
	slist.insert(slist.begin(), v.end() - 2, v.end());
	slist.insert(slist.end(), {"these", "words", "will", "go", "at", "the", "end"});
	for(list<string>::iterator iter = slist.begin(); iter != slist.end(); ++iter) {
		cout << *iter << " ";
	}
	cout <<endl;

	// list<string> lst;
	// auto iter = lst.begin();
	// string word;
	// while(cin >> word) {
	// 	iter = lst.insert(iter, word);   //等价于push_front
	// }
	// for(auto liter = lst.begin(); liter != lst.end(); liter++) {
	// 	cout << *liter << " ";
	// }
	// cout << endl;

	vector<int> c;
	c.push_back(12);
	c.push_back(22);
	// c.emplace_back("897-0590353403", 25, 15.99);
	// c.push_back(Sales_data("897-0590353404", 25, 15.99));
	if(!c.empty()) {
		auto val = *c.begin(), val2 = c.front();
		auto last = c.end();
		auto val3 = *(--last);
		auto val4 = c.back();
	}
	if(!c.empty()) {
		c.front() = 42;
		auto &v = c.back();
		v = 1024;
		vector<int>::value_type v2 = c.back();
		v2 = 0;
	}
	for(auto iter = c.begin(); iter != c.end(); iter++) {
		cout << *iter << " ";
	}
	cout << endl;

	list<int> lst = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	auto it = lst.begin();
	while(it != lst.end()) {
		if(*it % 2) {
			it = lst.erase(it);
		} else {
			++it;
		}
	}

	// list<int> ilist(10, 42);
	ilist.resize(15);
	ilist.resize(25, -1);
	ilist.resize(5);

	vector<int> vi = {0,1,2,3,4,5,6,7,8,9};
	auto iter = vi.begin();
	while(iter != vi.end()) {
		if(*iter % 2) {
			iter = vi.insert(iter, *iter);
			iter += 2;
		} else {
			iter = vi.erase(iter);
		}
	}
	for(auto iter = vi.begin(); iter != vi.end(); ++iter) {
		cout << *iter << " ";
	}
	cout << endl;

	vector<int> ivec;
	cout << " ivec: size: " << ivec.size()
		 << " capacity: " << ivec.capacity() << endl;
	for(vector<int>::size_type ix = 0; ix != 24; ++ix) {
		ivec.push_back(ix);
	}
	cout << " ivec: size: " << ivec.size()
		 << " capacity: " << ivec.capacity() << endl;	
	ivec.shrink_to_fit();
	cout << " ivec: size: " << ivec.size()
		 << " capacity: " << ivec.capacity() << endl;

	const char *cp = "Hello World!!!";
	char noNull[] = {'H', 'i'};
	string s1(cp);

	string s("hello world");
	string s2 = s.substr(0, 5);
	
	string name("r2d2");
	string number("0123456789");
	auto pos1 = name.find("Anna");
	cout << pos1 << endl;
	string::size_type pos = 0;
	while((pos = name.find_first_of(number, pos)) != string::npos) {
		cout << "found number at index: " << pos << " element is " << name[pos] << endl;
		++pos;
	}
	string river("Mississippi");
	auto first_pos = river.find("is");
	auto last_pos = river.rfind("is");
	cout << first_pos << " " << last_pos << endl;

	int i = 42;
	s = to_string(i);
	double d = stod(s);

	s2 = "pi = 3.14";
	d = stod(s2.substr(s2.find_first_of("+-.0123456789")));
	cout << d << endl;

	return 0;
}
