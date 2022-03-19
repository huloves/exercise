#include <iostream>
#include <string>
#include <vector>
#include <memory>

using namespace std;

int main()
{
	int n = 10;
	allocator<int> alloc;
	auto const p = alloc.allocate(n);
	vector<int> vi{1,2,3,4,5,6,7,8,9};
	int *p = alloc.allocate(vi.size() * 2);
	int *q = uninitialized_copy(vi.begin(), vi.end(), p);
	uninitialized_fill_n(q, vi.size(), 42);
	return 0;
}
