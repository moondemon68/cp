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
        int n;
        cin >> n;
        int a[2*n+5];
        for (int i=1;i<=2*n;i++) cin >> a[i];
        int maxi = 0, cur = 1;
        vector<int> v;
        for (int i=1;i<=2*n;i++) {
            if (a[i] > maxi) {
                if (i > 1) {
                    v.pb(i-cur);
                    cur = i;
                }
            }
            maxi = max(maxi, a[i]);
        }
        // for (auto x : v) cout << x << " ";
        bool dp[2*n+5][n+5];
        memset (dp,0,sizeof(dp));
        for (int i=0;i<=2*n;i++) dp[i][0] = 1;
        for (int i=1;i<=n;i++) dp[0][i] = 0;
        for (int i=1;i<=v.size();i++) {
            for (int j=1;j<=n;j++) {
                if (j < v[i-1]) dp[i][j] = dp[i-1][j];
                else dp[i][j] = dp[i-1][j] || dp[i-1][j-v[i-1]];
            }
        }
        if (dp[v.size()][n]) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}