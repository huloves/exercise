#include <iostream>

constexpr int size()
{
    return 1;
}

int main(int argc, char* argv[])
{
    int ival = 1024;
    int& ref_val = ival;
    int* p1 = nullptr;
    const int buf_size = 512;
    constexpr int mf = 20;
    constexpr int limit = mf + 1;
    constexpr int sz = size();
    
    std::cout << sz << std::endl;

    std::cout << ref_val << *p1 << std::endl;
}
