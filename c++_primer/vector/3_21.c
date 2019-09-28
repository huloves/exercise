#include <iostream>
#include <vector>

using namespace std;

int main()
{
    //vector<int> vi;
    //int i;
    vector<string> vs;
    string str;

    for(int j = 0; j < 3; j++) {
        cin >> str;
        vs.push_back(str);
    }

    //将所有单词变成大写形式
    /*for(decltype(vs.size()) i = 0; i < vs.size(); ++i) {
        for(decltype(vs[i].size()) temp = 0; temp < vs[i].size(); temp++)
            vs[i][temp] = toupper(vs[i][temp]);
    }*/

    for(auto it = vs.begin(); it != vs.end(); it++)
        cout << (*it) << endl;;
    //cout << endl;

    return 0;
}
