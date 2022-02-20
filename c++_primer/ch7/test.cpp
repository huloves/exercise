#include <iostream>
#include <string>
#include <vector>
#include "Sales_data.h"
#include "Person.h"

using namespace std;

int main(int argc, char *argv[])
{
    Sales_data totle("123");
    Sales_data totle2("qwe", 1, 3);
    Sales_data totle3;
    // Sales_data totle4(cin);
    cout << totle.isbn() << endl;
    print(cout, totle);
    cout << endl;
    print(cout, totle2);
    cout << endl;
    print(cout, totle3);
    cout << endl;
    // print(cout, totle4);
    // cout << endl;
    Person person("hqw", "huloves");
    // read(cin, person);
    print(cout, person);
    cout << endl;
    return 0;
}
