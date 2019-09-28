#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> ivec;
    int i;

    cout << "enter 10 number:" << endl;
    for(i = 0; i < 10; i++) {
        int temp(0);
        cin >> temp;
        ivec.push_back(temp);
    }

    //输出相邻两个元素的和
    /*for(i = 0; i < 10 - 1; i++) {
        cout << ivec[i] + ivec[i+1] << endl;
    }*/

    //输出第一个和最后一个元素的和
    for(i = 0; i < 10/2; i++) {
        cout << ivec[i] + ivec[10-1-i] << endl;
    }

    return 0;
}
