#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iterator>
#include <cstring>

using namespace std;

int main()
{
	std::string temp_string = "0000";
	std::string::const_pointer c_string = temp_string.c_str();
	cout << c_string << endl;

	cout << temp_string.size() << " " << temp_string.length() << endl;
	char *c_string_copy = new char[temp_string.size() + 1];
	memmove(c_string_copy, temp_string.c_str(), temp_string.size());
	c_string_copy[0] += 1;
	cout << temp_string << endl;
	temp_string = c_string_copy;
	cout << c_string_copy << endl;
	cout << temp_string << endl;

	int number = stoi(temp_string);
	cout << number << endl;

	//vector<int>和string的相互转换
	//string转vector<int>
	vector<int> ivec;
	for(int i = 0; i < temp_string.size(); i++) {
		ivec.push_back(int(temp_string[i]) - 48);
	}
	for(auto iter = ivec.begin(); iter != ivec.end(); iter++) {
		cout << *iter << endl;
	}
	//vector<int>转string - 方法1
	string s;
	for (auto x : ivec) {
		s += static_cast<char>(x + 48);
	}
	cout << s << endl;
	//vector<int>转string - 方法2
	string str;
	stringstream ss;
	copy(ivec.begin(), ivec.end(), ostream_iterator<int>(ss, ""));
	str = ss.str();
	cout << str << endl;

	return 0;
}
