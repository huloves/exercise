#include <iostream>
#include <vector>

using namespace std;

int main()
{
    //vector<int> vi;
    //int i;
    vector<string> vs;
    string str;

    for(int j = 0; j < 10; j++) {
        cin >> str;
        vs.push_back(str);
    }

    for(string &j : vs)
        cout << j << endl;;
    cout << endl;

    return 0;
}
