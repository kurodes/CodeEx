#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long base[20] = {
    1,2,6,24,120,
    720,5040,40320,362880,3628800,
    39916800,479001600,6227020800,87178291200,1307674368000,
    20922789888000,355687428096000,6402373705728000,121645100408832000,2432902008176640000
};

vector<long long> baseD;

void output(const vector<int> &P, const int &len)
{
    for(int i=0; i<len; ++i)
        cout << P[i] << " ";
    cout << endl;
}

void Cantor_to_index(const vector<int> &F, long long &index, const int &len) {
    index = 0;
    for (int i=0; i<len-1; i++) {
        //index += F[len-i-1]*base[i];
        long long a = F[len-i-2], b = base[i];
        index += a * b;
    }
}

void index_to_Cantor(const long long &index, vector<int> &F, const int &len) {
    long long rem = index;
    for (int i=len-2; i>=0; i--) {
        int e = (int) (rem/base[i]);
        F[len-2-i]=e;
        rem = rem % base[i];
    }
}

void perm_to_Cantor(const vector<int> &P, vector<int> &F, const int &len) {
    for (int i=0; i<len-1; i++) {
        int counter=0;
        for (int j=i+1; j<len; j++) {
            if (P[i]>P[j]) counter++;
        }
        F[i] = counter;
    }
}

void Cantor_to_perm(const vector<int> &F, vector<int> &P, const int &len) {
    vector<int> U(len+1, 0);
    for (int i=0; i<len-1; i++) {
        P[i] = F[i]+1;
        for (int j=1; j<=P[i]; j++) {
            if (U[j] == 1) P[i]++;
        }
        U[P[i]] = 1;
    }
    for (int i=1; i<=len; i++) {
        if (U[i]==0) P[len-1]=i;
    }
}

void lexicographical_order(const vector<int> &P, const long long &k, const int &len)
{
    // cantor factor array should be formalized !
    vector<int> F(len-1, 0);
    perm_to_Cantor(P, F, len);
    long long index;
    Cantor_to_index(F, index, len);
    index += k;
    vector<int> next_F(len-1, 0);
    index_to_Cantor(index, next_F, len);
    vector<int> next_P(len, 0);
    Cantor_to_perm(next_F, next_P, len);
    output(next_P, len);
}

void inc_to_index(const vector<int> &Inc, long long &index, const int &len) {
    index = 0;
    for (int i=0; i<len-1; i++) {
        //index += F[len-i-1]*base[i];
        long long a = Inc[len-i-2], b = base[i];
        index += a * b;
    }
}

void index_to_inc(const long long &index, vector<int> &Inc, const int &len) {
    long long rem = index;
    for (int i=len-2; i>=0; i--) {
        int e = (int) (rem/base[i]);
        Inc[len-2-i]=e;
        rem = rem % base[i];
    }
}

void inc_to_perm(const vector<int> &Inc, vector<int> &P, const int &len) {
        // Inc[i], i <> len-i
    for (int i=0; i<len-1; i++) {
        if (Inc[i]==0) {
            for (int k=len-1; k>=0; k--) {
                if (P[k]==0) {
                    P[k] = len-i;
                    break;
                }
            }
        } else {
            int counter = 0;
            int j = len-2;
            while (j >= 0) {
                if (P[j+1] < len-i) {
                    counter++;
                }
                if (counter == Inc[i] && P[j] == 0) {
                    P[j] = len-i;
                    break;
                }
                j--;
            }
        }
    }
    for (int i=0; i<len; i++) {
        if (P[i] == 0) P[i]=1;
    }
}

void perm_to_inc(const vector<int> &P, vector<int> &Inc, const int &len) {
    for (int i=0; i<len-1; i++) {
        // P[i]
        int counter = 0;
        for (int j=i+1; j<len; j++) {
            if (P[i] > P[j]) counter++;
        }
        Inc[len-P[i]] = counter;
    }
}

void incremental_radix(const vector<int> &P, const long long &k, const int &len) {
    vector<int> Inc(len-1, 0);
    perm_to_inc(P, Inc, len);
    long long index;
    inc_to_index(Inc, index, len);
    index += k;
    vector<int> resInc(len-1, 0);
    index_to_inc(index, resInc, len);
    vector<int> resP(len, 0);
    inc_to_perm(resInc, resP, len);
    output(resP, len);
}

void gen_baseD(const int n) {
    baseD.resize(n, 0);
    baseD[0] = 1;
    for (int i=1; i<n; i++) {
        long long multi = 1;
        for (int j=n; j>=n-i+1; j--) {
            multi *= j;
        }
        baseD[i] = multi;
    }
}

void index_to_dec(const long long &index, vector<int> &Dec, const int &len) {
    long long rem = index;
    for (int i=len-2; i>=0; i--) {
        int e = (int) (rem/baseD[i]);
        Dec[len-2-i]=e;
        rem = rem%baseD[i];
    }
}

void dec_to_index(const vector<int> &Dec, long long &index, const int &len) {
    index = 0;
    for (int i=0; i<len-1; i++) {
        //index += F[len-i-1]*base[i];
        long long a = Dec[len-i-2], b = baseD[i];
        index += a * b;
    }
}

void dec_to_perm(const vector<int> &Dec, vector<int> &P, const int &len) {
    vector<int> Inc(len-1, 0);
    for (int i=0; i<len-1; i++) {
        Inc[len-i-2] = Dec[i];
    }
    inc_to_perm(Inc, P, len);
}

void perm_to_dec(const vector<int> &P, vector<int> &Dec, const int &len) {
    vector<int> Inc(len-1, 0);
    perm_to_inc(P, Inc, len);
    for (int i=0; i<len-1; i++) {
        Dec[i] = Inc[len-i-2];
    }
}

void decremental_radix(const vector<int> &P, const long long &k, const int &len) {
    vector<int> Dec(len-1, 0);
    perm_to_dec(P, Dec, len);
    long long index;
    dec_to_index(Dec, index, len);
    index += k;
    vector<int> resDec(len-1, 0);
    index_to_dec(index, resDec, len);
    vector<int> resP(len, 0);
    dec_to_perm(resDec, resP, len);
    output(resP, len);
}

void adj_to_perm(const vector<int> &Adj, vector<int> &P, const int &len) {
    vector<int> b(len+1, 0);
    for (int i=0; i<len-1; i++) {
        b[i+2] = Adj[i];
    }
    for (int i=len; i>=2; i--) {
        if (i==2 || (i%2==0 && (b[i-1]+b[i-2])%2==0) || (i%2==1 && b[i-1]%2==0)) {
            int pos = len;
            int sp=b[i]+1;
            while (sp>0) {
                pos--;
                if (P[pos] == 0) {
                    sp--;
                }
            }
            P[pos] = i;
        } else {
            int pos = -1;
            int sp=b[i]+1;
            while (sp>0) {
                pos++;
                if (P[pos] == 0) {
                    sp--;
                }
            }
            P[pos] = i;
        }
    }
    for (int i=0; i<len; i++) {
        if (P[i]==0) {
            P[i]=1;
        }
    }
}

void perm_to_adj(const vector<int> &P, vector<int> &Adj, const int &len) {
    vector<int> pos(len+1, 0);
    vector<int> b(len+1, 0);
    for (int i=0; i<len; i++) {
        pos[P[i]] = i;
    }
    for (int i=2; i<=len; i++) {
        if (i==2 || (i%2==0 && (b[i-1]+b[i-2])%2==0) || (i%2==1 && b[i-1]%2==0)) {
            int p = pos[i];
            if (p+1 > len-1) {
                b[i]=0;
            } else {
                int counter = 0;
                for (int j=p+1; j<len; j++) {
                    if (P[p]>P[j]) {
                        counter++;
                    }
                }
                b[i]=counter;
            }
        } else {
            int p = pos[i];
            if (p-1 < 0) {
                b[i]=0;
            } else {
                int counter = 0;
                for (int j=p-1; j>=0; j--) {
                    if (P[p]>P[j]) {
                        counter++;
                    }
                }
                b[i]=counter;
            }
        }
        Adj[i-2] = b[i];
    }
}

void adjacent_switch(const vector<int> &P, const long long &k, const int &len) {
    vector<int> Adj(len-1, 0);
    perm_to_adj(P, Adj, len);
    long long index;
    dec_to_index(Adj, index, len);
    index += k;
    vector<int> resAdj(len-1, 0);
    index_to_dec(index, resAdj, len);
    vector<int> resP(len, 0);
    adj_to_perm(resAdj, resP, len);
    output(resP, len);
}

int main()
{
    int n, t;
    long long k;
    vector<int> P;

    cin >> n >> t >> k;
    P.resize(n);
    for (int i=0; i<n; i++) {
        cin >> P[i];
    }

    switch (t)
    {
    case 1:
        lexicographical_order(P, k, n);
        break;
    case 2:
        incremental_radix(P, k, n);
        break;
    case 3:
        gen_baseD(n);
        decremental_radix(P, k, n);
        break;
    case 4:
        gen_baseD(n);
        adjacent_switch(P, k, n);
        break;
    default:
        break;
    }
    return 0;
}
