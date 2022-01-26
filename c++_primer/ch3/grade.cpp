#include <iostream>
#include <vector>

using namespace std;
using std::cout;

int main()
{
	vector<unsigned int> scores(11, 0);
	unsigned int grade;
	while(cin >> grade) {
		if(grade <= 100) {
			++scores[grade/10];
		}
	}
	for(unsigned int temp : scores) {
		cout << temp << " ";
	}
	cout << endl;
	return 0;
}
