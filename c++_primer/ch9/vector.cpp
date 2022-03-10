#include <iostream>
#include <vector>
#include <string>
#include <deque>
#include <list>
#include <forward_list>
#include <array>

using namespace std;

int main(int argc, char *argv[])
{
	list<string> authors = {"milton", "shankespeare", "Austen"};
	vector<const char*> articles = {"a", "an", "the"};

	list<string> list2(authors);
	// deque<string> authList(authors);
	// vector<string> words(articles);
	forward_list<string> words(articles.begin(), articles.end());
	array<int, 10>::size_type i;
	array<int, 10> digits = {0,1,2,3,4,5,6,7,8,9};
	array<int, 10> copy = digits;
	// assgin
	list<string> names;
	vector<const char*> oldstyle;
	// names = oldstyle;
	names.assign(oldstyle.cbegin(), oldstyle.cend());
	list<string> slist1(1);
	slist1.assign(10, "Hiya!");
	return 0;
}
