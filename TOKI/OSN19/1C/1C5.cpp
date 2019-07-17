#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define LL long long
using namespace std;

int main () {
    //clock_t start = clock();
    ifstream fin("rekreasi_8.in");
    ofstream fout("rekreasi_8.out");
    int r,c;
    fin >> r >> c;
    string s;
    fin >> s;
    char a[r+5][c+5];
    for (int i=1;i<=r;i++) {
        string s;
        fin >> s;
        for (int j=1;j<=c;j++) {
            a[i][j]=s[j-1];
        }
    }
    for (int i=1;i<=r;i++) {
        for (int j=1;j<=c;j++) {
            if (i==2&&a[i][j]=='.'&&j!=1) fout << 'x'; else fout << a[i][j];
        }
        fout << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}