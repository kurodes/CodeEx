// defaults.cpp -- cout default formats
#include <iostream>
int main()
{
    using std::cout;
    double f2 = 1.0 / 9.0;
    cout << f2 << ":\n";
    cout << (f2 * 1.0e4) << ":\n";
    double f3 = 2.3e-4;
    cout << f3 << ":\n";
    cout << f3 / 10 << ":\n";
    return 0;
}