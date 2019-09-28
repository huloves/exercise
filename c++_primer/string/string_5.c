/*2019.9.27
 * 问题：编写一段程序，读入一个包含标点符号的字符串，将标点符号去除后输出字符剩余的部分。
 **/
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str;

    cout << "enter a string: " << endl;
    cin >> str;
    cout << str << endl;

    for(decltype(str.size()) i = 0; i != str.size(); i++){
        //cout << i << endl;
        if(ispunct(str[i])){
            for(decltype(str.size()) j = i; j < str.size(); j++){
                str[j] = str[j+1];
            }
            i--;
        }
    }

    cout << str << endl;

    return 0;
}
