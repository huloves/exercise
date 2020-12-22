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
    string str = "123456";
    auto beg = str.begin(), end = str.end();
    auto mid = str.begin() + (end - beg) / 2;
    
    char sought = '5';

    while(mid != str.end() && *mid != sought) {
        if(sought < *mid) {
            end = mid;
        } else {
            beg = mid + 1;
        }
        mid = beg + (end - beg) / 2;
    }
    cout << *mid << endl;

    return 0;
}
