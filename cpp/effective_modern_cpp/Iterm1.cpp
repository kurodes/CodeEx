#include <iostream>
using namespace std;

template<typename T>
T twice(const T& x)
{
    return 2*x;
}

int main()
{
    int a = 1;
    int b = twice(a);

    double c = 1.1;
    double d = twice(c);
    return 0;
}