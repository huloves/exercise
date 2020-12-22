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
    string s("hello world!");
    const char* str = s.c_str();
    int int_arr[] = {0, 1, 2, 3, 4, 5};
    
    vector<int> ivec(begin(int_arr), end(int_arr));

    int ia[3][4] = {
        {0, 1, 2, 3},
        {4, 5, 6, 7},
        {8, 9, 10, 11}
    };

    using int_array = int[4];   //类型别名

    // for(auto it = s.begin(); it != s.end() && !isspace(*it); it++) {
    //     *it = toupper(*it);
    // }
    auto beg = s.begin();
    while(beg != s.end() && !isspace(*beg)) {
        *beg = toupper(*beg);
        beg++;
    }

    size_t cnt = 1;
    for(auto &row : ia) {
        for(auto &col : row) {
            col = cnt;
            cnt++;
        }
    }
    vector<int>::size_type cnt_ = ivec.size();
    for(vector<int>::size_type ix = 0; ix != ivec.size(); ix++, cnt_--) {
        ivec[ix] = cnt_;
    }
    for(auto i : ivec) {
        cout << i << ' ';
    }
    cout << "asdf" << endl;
    for(auto &row : ia) {
        for(auto col : row) {
            cout << col << "\t";
        }
        cout << endl;
    }
    
    return 0;
}
