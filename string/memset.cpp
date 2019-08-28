#include <iostream>
using namespace std;
int main() {
    for (int i=0; i < 1; i++) {
        char data[16384];
        memset(data, '0'+i%10, 16384);
        for (int j=0; j < 16384; j++) {
            cout << data[j];
        }
        cout << endl;
    }
    return 0;
}
