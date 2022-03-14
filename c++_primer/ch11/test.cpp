#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <utility>
#include <unordered_set>
#include <unordered_map>
#include "Sales_data.h"

using namespace std;

bool compareIsin(const Sales_data &lhs, const Sales_data &rhs) {
	return lhs.isbn() < rhs.isbn();
}

int main()
{
	map<string , size_t> word_count;   // 空容器
	set<string> exclude = {"The", "But", "And", "Or", "An", "A", "the", "but", "and", "or", "an", "a"};
	map<string, string> authors = { {"Joyce", "Jmaes"},
									{"Austen", "Jame"},
									{"Dickens", "Charles"} };
	vector<int> ivec;
	for(vector<int>::size_type i = 0; i != 10; i++) {
		ivec.push_back(i);
		ivec.push_back(i);
	}
	set<int> iset(ivec.cbegin(), ivec.cend());
	multiset<int> miset(ivec.cbegin(), ivec.cend());
	cout << ivec.size() << endl;
	cout << iset.size() << endl;
	cout << miset.size() << endl;

	multiset<Sales_data, decltype(compareIsin)*> bookstore_set(compareIsin);

	pair<string, string> anon;
	// pair<string, size_t> word_count;
	pair<string, vector<int>> line;
	pair<string, string> author_{"James", "Joyce"};

	string word = "hello";
	word_count[word]++;
	word_count["hello"]++;
	auto map_it = word_count.begin();
	cout << map_it->first << " " << map_it->second << endl;;
	// map_it->first = "new key";   // error
	map_it->second++;
	cout << map_it->first << " " << map_it->second << endl;

	using SD_multiset = unordered_multiset<Sales_data, decltype(hasher)*, decltype(eqOp)*>;
	// 参数是捅大小、哈希函数指针和相等性判断运算符指针
	SD_multiset bookstore(42, hasher, eqOp);

	return 0;
}
