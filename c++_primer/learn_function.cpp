#include <iostream>
#include <string>
#include <vector>
#include <initializer_list>
#include "Sales_item.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::begin;
using std::end;

void reset(int* ip)
{
    *ip = 0;
    ip = 0;
}

void reset(int& i)
{
    i = 0;
}

bool is_shorter(const string& s1, const string& s2)
{
    return s1.size() < s2.size();
}

string::size_type find_char(const string& s, char c, string::size_type& occurs)
{
    auto ret = s.size();
    occurs = 0;
    for(decltype(ret) i=0; i!=s.size(); i++) {
        if(s[i] == c) {
            if(ret == s.size()) {
                ret = i;
            }
            occurs++;
        }
    }
    return ret;
}

bool is_sentence(const string& s)
{
    string::size_type ctr = 0;
    return (find_char(s, '.', ctr) == s.size() - 1) && (ctr == 1);
}

void error_msg(initializer_list<string> il)
{
    for(string::size_type beg = il.begin(); beg != il.end(); beg++) {
        cout << *beg << endl;
    }
}

int main(int argc, char** argv)
{
    int n = 0, i = 42;
    int* p = &n, *q = &i;
    *p = 42;
    p = q;
    string::size_type ctr = 0;

    string::size_type index = find_char("hello world!", 'o', ctr);
    reset(i);

    cout << "i = " << i << endl;
    cout << "index = " << index << " ctr = " << ctr << endl;
    
    return 0;
}
