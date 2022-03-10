#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int main()
{
	ofstream out2("file1", ofstream::out);
	ofstream out3("file1", ofstream::out | ofstream::trunc);
	ofstream app("file2", ofstream::app);
	ofstream app2("file2", ofstream::out | ofstream::app);
	ofstream out;
	out.open("test.txt", ofstream::out | ofstream::app);
	out << "0-201-70353-x 3 20.00" << endl;
	out.close();
	return  0;
}
