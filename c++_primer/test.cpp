#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main(int argc, char* argv[])
{
    string s1;
    string s2 = s1;
    string s3 = "hiya";
    string s4(10, 'c');
    string s5 = "hiya";
    string s6("hiya");
    string s7(10, 'c');
    string s8 = string(10, 'c');
    string str1 = "hello", str2 = "world";
    string str3 = str1 + ", " + str2 + '\n';
    
    string str("hello world!!!");
    for(decltype(str.size()) index = 0; index != str.size() && !isspace(str[index]); index++) {
        str[index] = toupper(str[index]);
    }
    cout << str << endl;

    return 0;
}
