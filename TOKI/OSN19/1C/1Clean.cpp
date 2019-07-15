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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ifstream fin("rekreasi_4.ou");
    ofstream fout("rekreasi_4.out");
    int r,c;
    fin >> r >> c;
    for (int i=1;i<=r;i++) {
        string s;
        fin >> s;
        for (int j=0;j<c;j++) {
            if (s[j]=='_'||s[j]=='o') fout << '.'; else fout << s[j];
        }
        fout << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}