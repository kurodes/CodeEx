#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void lexico_Cantor_to_permutation(const vector<int> &M, vector<int> &P) {
    int len = M.size()+1;
    P.resize(len);
    vector<int> U(len+1, 0);
    for (int i=0; i<len-1; i++) {
        P[i] = M[i]+1;
        for (int j=1; j<=P[i]; j++) {
            if (U[j] == 1) P[i]++;
        }
        U[P[i]] = 1;
    }
    for (int i=1; i<=len; i++) {
        if (U[i]==0) P[len-1]=i;
    }
}

void lexico_permutation_to_Cantor(vector<int> &M, const vector<int> &P) {
    int len = P.size();
    M.resize(len-1);
    for (int i=0; i<len-1; i++) {
        int counter=0;
        for (int j=i+1; j<len; j++) {
            if (P[i]>P[j]) counter++;
        }
        M[i] = counter;
    }
}

int main() {
    int a[8] = {7,2,6,4,2,3,2,1};
    vector<int> M(a, a+8);
    vector<int> P;
    lexico_Cantor_to_permutation(M,P);
    int len = P.size();
    for (int i = 0; i < len; i++)
    {
        cout << P[i] << " ";
    }
    cout << endl;

    int b[9] = {8,3,9,6,4,7,5,2,1};
    vector<int> MM;
    vector<int> PP(b, b+9);;
    lexico_permutation_to_Cantor(MM,PP);
    int len2 = MM.size();
    for (int i = 0; i < len2; i++)
    {
        cout << MM[i] << " ";
    }
    cout << endl;

    return 0;
}