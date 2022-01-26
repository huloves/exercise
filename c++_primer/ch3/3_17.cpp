#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char** argv)
{
	vector<string> string_vec;
	string str;
	while(cin >> str) {
		string_vec.push_back(str);
	}
	for(string &temp : string_vec) {
		for(char &ch : temp) {
			ch = toupper(ch);
		}
	}
	for(string temp : string_vec) {
		cout << temp << endl;
	}
	return 0;
}
