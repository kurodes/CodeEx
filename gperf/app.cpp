#include <fstream>
#include <iostream>
#include <vector>
#include <cstring>
#include <gperftools/profiler.h>

using namespace std;

// int REC[2][100000];

int Search_Path(vector<int>* M0, vector<int>* M1, int CurColor, int S, int T)
{
	if (S == T) return 1;
 
	int P = 0;
    vector<int>::iterator it0 = M0[S].begin();
    vector<int>::iterator it1 = M1[S].begin();
    if (CurColor != 0) {
        for (; it0 != M0[S].end(); ++it0) {
            // if (REC[0][*it0] != -1) P += REC[0][*it0];
            //else 
            P += Search_Path(M0, M1, 0, *it0, T);
        }
    }
    if (CurColor != 1) {
        for (; it1 != M1[S].end(); ++it1) {
            // if (REC[1][*it1] != -1) P += REC[1][*it1];
            //else 
            P += Search_Path(M0, M1, 1, *it1, T);
        }
    }
    if (P >= 10007) P = P % 10007;
    // REC[CurColor][S] = P;
	return P;
}

int main() {
    ProfilerStart("./app.prof");
    ifstream fin("4.txt");

    // memset(REC, -1, sizeof(int)*2*100000);

    int V, E, S, T;
    fin >> V >> E >> S >> T;

    vector<int> M0[V];
    vector<int> M1[V];
    int a, b, c;
    for (int i = 0; i < E; i++) {
        fin >> a >> b >> c;
        if (c == 0) {
            M0[a].push_back(b);
        } else {
            M1[a].push_back(b);
        }
    }
    cout << Search_Path(M0, M1, 0, S, T) + Search_Path(M0, M1, 1, S, T) << endl;
    // cout << M0[0].size() << M1[0].size() << M1[2].size();
    ProfilerStop();
    return 0;
}