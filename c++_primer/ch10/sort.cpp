#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;
using namespace std::placeholders;

auto f = [](const string &a, const string &b) {
	return a.size() < b.size();
};

bool isShorter(const string &s1, const string &s2) {
	return s1.size() < s2.size();
}

void elimDups(vector<string> &words) {
	sort(words.begin(), words.end());
	auto end_unique = unique(words.begin(), words.end());
	words.erase(end_unique, words.end());
	return;
}

bool check_size(const string &s, string::size_type sz) {
	return s.size() >= sz;
}

void biggies(vector<string> &words, vector<string>::size_type sz) {
	elimDups(words);
	// stable_sort(words.begin(), words.end(), f);
	std::stable_sort(words.begin(), words.end(), 
		[](string const& lhs, string const& rhs) {
		return lhs.size() < rhs.size(); }
	);
	// auto wc = find_if(words.begin(), words.end(), 
			// [sz](const string &a)
				// { return a.size() >= sz; });
	vector<string>::iterator wc = find_if(words.begin(), words.end(), bind(check_size, placeholders::_1, sz));
	// auto count = words.end() - wc;
	// cout << count << " " << make_plural(count, "word", "s") << " of length " << sz << " or longer" << endl;
	for_each(wc, words.end(), [](const string &s){cout << s << " ";});
	cout << endl;
}

int main()
{
	vector<string> svec = {"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};
	// sort(svec.begin(), svec.end(), isShorter);
	// for(string tmp : svec) {
	// 	cout << tmp << " ";
	// }
	// cout << endl;
	// elimDups(svec);
	// for(string tmp : svec) {
	// 	cout << tmp << " ";
	// }
	// cout << endl;
	// sort(svec.begin(), svec.end(), isShorter);
	// for(auto iter = svec.cbegin(); iter != svec.cend(); iter++) {
	// 	cout << *iter << " ";
	// }
	// cout << endl;
	biggies(svec, 4);
	auto check6 = bind(check_size, placeholders::_1, 6);
	string s = "helloi!!!!!";
	bool b1 = check6(s);
	if(b1 == true) {
		cout << "AAAA" << endl;
	}
	return 0;
}
