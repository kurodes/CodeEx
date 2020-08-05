#include <iostream>
#include <string>
#include <stdint.h>

using namespace std;

struct ID {
    uint16_t a : 2;
    uint16_t b : 4;
    uint16_t c : 8;
};

int main() {
    ID x = {2, 2, 2};
    cout << sizeof(x) << endl;
    // cout << sizeof(unsigned long) << endl;

    return 0;
}