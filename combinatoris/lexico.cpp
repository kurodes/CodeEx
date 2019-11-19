/**
 * cantor factor formalize !!!!
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
 
void output(vector<int> res)
{
    for(int i=0; i<res.size(); ++i)
        cout << res[i] << " ";
    cout << endl;
}
 
void lexicographical_order(vector<int> a, long long k)
{
    int len = a.size();
    if(len < 2) return;
    while (k > 0) {
        int i,j;
        for(i=len-2; i>=0; --i) {
            if(a[i]<a[i+1]) break;
            else if(i==0) return;
        }
        for(j=len-1; j>i; --j) {
            if(a[j]>a[i]) break;
        }
        iter_swap(a.begin()+i, a.begin()+j);
        reverse(a.begin()+i+1, a.end());
        --k;
    }
    output(a);
}

int main()
{
    int n, t;
    long long k;
    vector<int> a;

    cin >> n >> t >> k;
    a.resize(n);
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }

    switch (t)
    {
    case 1:
        lexicographical_order(a, k);
        break;
    
    default:
        break;
    }

    return 0;
}