/**
 * ./out n
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
 
void output(vector<int> res)
{
    for(int i=0; i<res.size(); ++i)
        cout << res[i] << " ";
    cout << endl;
}
 
void lexicographical_order(vector<int> a)
{
    int len = a.size();
    if(len < 2) return;
    while (true) {
        output(a);
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
    }
}

int main() {
    int n;
    vector<int> a;
    cin >> n;
    for (int i=0; i<n; i++) {
        a.push_back(i+1);
    }
    lexicographical_order(a);

    return 0;
}