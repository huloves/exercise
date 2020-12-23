#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::begin;
using std::end;

int main(int argc, char** argv)
{
    int j = 2, i = 1;
    double slope = static_cast<double>(j) / i;
    double d = 3.1415926;
    void* p = &d;
    double* dp = static_cast<double*>(p);
    int* ip;
    char* pc = reinterpret_cast<char*>(ip);
    vector<int> v = {0,1,2,3,4,5,6,7,8,9};

    for(auto &r : v) {
        r *= 2;
    }
    for(auto r : v) {
        cout << r << ' ';
    }
    cout << endl;

    return 0;
}
