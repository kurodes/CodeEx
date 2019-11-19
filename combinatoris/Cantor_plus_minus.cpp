#include <iostream>
#include <vector>
using namespace std;

long long base[20] = {
    1,2,6,24,120,
    720,5040,40320,362880,3628800,
    39916800,479001600,6227020800,87178291200,1307674368000,
    20922789888000,355687428096000,6402373705728000,121645100408832000,2432902008176640000
};

/* 
 * Fa,Fb,Fc.size() = len-1 
 */
void Cantor_plus(vector<int> Fa, vector<int> Fb, vector<int> &Fr, int len) {
    reverse(Fa.begin(), Fa.end());
    reverse(Fb.begin(), Fb.end());
    for (int i=0; i<len; i++) {
        int tmp = Fa[i] + Fb[i];
        Fr[i] = tmp % 
    }
}


int main() {

    return 0;
}