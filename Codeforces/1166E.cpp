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
    int m,n;
    cin >> m >> n;
    bool a[m+5][n+5];
    memset (a,0,sizeof(a));
    for (int i=1;i<=m;i++) {
        int k;
        cin >> k;
        for (int j=1;j<=k;j++) {
            int x;
            cin >> x;
            a[i][x]=1;
        }
    }
    for (int i=1;i<=m;i++) {
        for (int j=1;j<=m;j++) {
            if (i==j) continue;
            bool y=0;
            for (int k=1;k<=n;k++) {
                if (a[i][k]&&a[j][k]) {
                    y=1;
                }
            }
            if (!y) {
                cout << "impossible" << endl;
                return 0;
            } 
        }
    }
    cout << "possible" << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}