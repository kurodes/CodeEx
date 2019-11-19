#include <iostream>
#include <vector>
using namespace std;

long long base[20] = {
    1,2,6,24,120,
    720,5040,40320,362880,3628800,
    39916800,479001600,6227020800,87178291200,1307674368000,
    20922789888000,355687428096000,6402373705728000,121645100408832000,2432902008176640000
};

void index_to_Cantor(const long long &index, vector<int> &F) {
    long long rem = index;
    for (int i=19; i>=0; i--) {
        int e = rem / base[i];
        if (e != 0) {
            F.push_back(e);
            rem = rem % base[i];
        }
    }
}

void Cantor_to_index(long long &index, const vector<int> &F) {
    index = 0;
    int len = F.size();
    for (int i=0; i<len; i++) {
        //index += F[len-i-1]*base[i];
        long long a = F[len-i-1], b = base[i];
        index += a * b;
    }
}

int main() {
    vector<long long> base(21, 1);
    for (int i=1; i<=20; i++) {
        for (int j = i; j >= 1; j--) {
            base[i] *= j;
        }
        cout << base[i] << ",";
    }
    cout << endl;

    long long index = 297191;
    vector<int> F;
    index_to_Cantor(index, F);
    for (int i=0; i<F.size(); i++) {
        cout << F[i];
    }
    cout << endl;

    int a[8] = {7,2,6,4,2,3,2,1};
    vector<int> FF(a, a+8);
    long long res;
    Cantor_to_index(res, FF);
    cout << res << endl;
    return 0;
}