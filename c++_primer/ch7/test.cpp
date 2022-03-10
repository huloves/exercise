#include <iostream>
#include <string>
#include <vector>
#include "Sales_data.h"
#include "Person.h"
#include "Account.h"

using namespace std;

int main(int argc, char *argv[])
{
    Sales_data totle("123");
    Sales_data totle2("qwe", 1, 3);
    Sales_data totle3;
    Sales_data totle4();
    double r;
    r = Account::rate();
    cout << r << endl;
    cout << "hi!" << ends;
    cout << "hello" << endl;
    return 0;
}
