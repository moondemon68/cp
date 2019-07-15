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
    ifstream fin("mengawasi_5.in");
    ofstream fout("mengawasi_5.out");
    int r,c;
    fin >> r >> c;
    char a[r+5][c+5];
    for (int i=1;i<=r;i++) {
        string s;
        fin >> s;
        for (int j=1;j<=c;j++) {
            a[i][j]=s[j-1];
        }
    }
    char b[r+5][c+5];
    for (int i=1;i<=r;i++) {
        for (int j=1;j<=c;j++) {
            if (a[i][j]=='.'){
                if ((i+j)%2==0) b[i][j]='>';
                else b[i][j]='.';
            } else b[i][j]='x';
        }
    }
    for (int i=1;i<=r;i++) {
        if (b[i][1]=='x') {
            for (int j=c;j>=1;j--) {
                if ((i+j)%2==0&&b[i][j]=='>') {
                    b[i][j]='<';
                }
            }
        }
    }
    for (int i=1;i<=r;i++) {
        for (int j=1;j<=c;j++) {
            fout << b[i][j];
        }
        fout << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}