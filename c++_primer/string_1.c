#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str("hello world");

    /*for(char &c:str) {
        c = 'x';
    }*/
    decltype(str.size()) index = 0;
    while(index < str.size()) {
        str[index] = 'x';
        index++;
    }

    cout << str << endl;

    return 0;
}
