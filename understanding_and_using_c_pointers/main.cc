#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    if (NULL == (void *)0)
    {
        cout << "NULL == (void *)0" << endl;
    }
    if (nullptr == (void *)0)
    {
        cout << "nullptr == (void *)0" << endl;
    }
    void *p;
    cout << p << endl;
    cout << p + 1 << endl;

    int a = 0x12345678;
    char *b = (char *)(&a);
    for (int i = 0; i < 4; i++)
        printf("%x", *((unsigned char *)(b++)));

    return 0;
}
