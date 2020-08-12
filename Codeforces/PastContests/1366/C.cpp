#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define INF 1234567890
#define pii pair<int,int>
#define LL long long
using namespace std;

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc;
    cin >> tc;
    while (tc--) {
        int n,m;
        cin >> n >> m;
        int a[n+5][m+5];
        for (int i=1;i<=n;i++) {
            for (int j=1;j<=m;j++) {
                cin >> a[i][j];
            }
        }
        int c[n+m+5], d[n+m+5];
        memset (c,0,sizeof(c));
        memset (d,0,sizeof(d));
        for (int i=1;i<=n;i++) {
            for (int j=1;j<=m;j++) {
                if (a[i][j] == 1) c[i+j]++; else d[i+j]++;
            }
        }
        int ans = 0;
        for (int i=2;i<=(n+m+1)/2;i++) {
            // cout << i << " " << n+m-i+2 << c[i] << c[n+m-i+2] << d[i] << d[n+m-i+2] << endl;
            ans += min(c[i]+c[n+m-i+2],d[i]+d[n+m-i+2]);
        }
        cout << ans << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}