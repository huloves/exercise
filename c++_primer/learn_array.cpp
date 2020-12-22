#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main(int argc, char** argv)
{
    string s("hello world!");
    const char* str = s.c_str();
    int int_arr[] = {0, 1, 2, 4, 5};

    vector<int> ivec(begin(int_arr), end(int_arr));

    cout << s << endl;
    cout << str << endl;
    
    return 0;
}
