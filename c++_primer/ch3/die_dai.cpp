#include <iostream>
#include <string>

using namespace std;

int main(int argc, char** argv)
{
	string s("some string");
	if(s.begin() != s.end()) {
		auto it = s.begin();
		*it = toupper(*it);
	}
	cout << s << endl;
	for(auto it = s.begin(); it != s.end() && !isspace(*it); it++) {
		*it = toupper(*it);
	}
	cout << s << endl;
	return 0;
}
