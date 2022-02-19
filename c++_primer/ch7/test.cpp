#include <iostream>
#include <string>
#include <vector>
#include "Sales_data.h"

using namespace std;

int main(int argc, char *argv[])
{
    Sales_data totle;
    totle.bookNo = "123";
    cout << totle.isbn() << endl;
    return 0;
}
