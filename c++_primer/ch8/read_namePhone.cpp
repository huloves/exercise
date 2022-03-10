#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "PersonInfo.h"

using namespace std;

bool valid(string num);
string format(string num);

int main(int argc, char *argv[])
{
	string line, word;
	vector<PersonInfo> people;
	while(getline(cin, line)) {
		PersonInfo info;
		istringstream record(line);
		record >> info.name;
		while(record >> word) {
			info.phones.push_back(word);
		}
		people.push_back(info);
	}

	for(const auto &entry : people) {
		ostringstream formatted, badNums;
		for(const auto &nums : entry.phones) {
			if(!valid(nums)) {
				badNums << " " << nums;
			} else {
				formatted << " " << format(nums);
			}
		}
		if(badNums.str().empty()) {
			cout << entry.name << "" << formatted.str() << endl;
		} else {
			cerr << "input error: " << entry.name << " invalid nameer(s) " << badNums.str() << endl;
		}
	}
	return 0;
}
