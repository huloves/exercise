#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char** argv)
{
	vector<int> vec_int;
	int temp;
	while(cin >> temp) {
		vec_int.push_back(temp);
	}
	int tmp = 0;
	// for(int temp : vec_int) {
		// tmp++;
	// }
	tmp = vec_int.size();
	for(int i = 0; i < tmp - 1; i++) {
		cout << vec_int[i] + vec_int[i+1] << endl;
	}
	for(int i = 0; i < tmp / 2; i++) {
		cout << vec_int[i] + vec_int[tmp-i-1] << endl;
	}
	return 0;
}
