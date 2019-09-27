/*
 * 问题：
 * 下面的范围for语句合法么？如果合法，c的类型是什么？
 * 答：合法，字符串常量*/
#include <iostream>
#include <string>
using namespace std;

int main()
{
    const string s = "Keep out!";
    for(auto &c : s) {
        cout << c;
    }
    cout << endl;
    return 0;
}
