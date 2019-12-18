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
    int n;
    cin >> n;
    char a[n+5][n+5];
    for (int i=0;i<n+3;i++) {
        for (int j=0;j<n+3;j++) {
            a[i][j]='#';
        }
    }
    for (int i=1;i<=n;i++) {
        string s;
        cin >> s;
        for (int j=1;j<=n;j++) {
            a[i][j]=s[j-1];
        }
    }
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=n;j++) {
            if (a[i][j]=='.'&&a[i+1][j-1]=='.'&&a[i+1][j]=='.'&&a[i+1][j+1]=='.'&&a[i+2][j]=='.') {
                a[i][j]='#';
                a[i+1][j-1]='#';
                a[i+1][j]='#';
                a[i+1][j+1]='#';
                a[i+2][j]='#';
            }
        }
    }
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=n;j++) {
            if (a[i][j]=='.') {
                cout << "NO" << endl;
                return 0;
            }
        }
    }
    cout << "YES" << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}