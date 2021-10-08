#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define INF 1234567890
#define pii pair<LL,LL>
#define LL long long
using namespace std;

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    LL n,m;
    cin >> n >> m;
    LL a[n+5];
    for (LL i=1;i<=n;i++) cin >> a[i];
    LL dp[n+5][m+5];
    memset (dp,0,sizeof(dp));
    for (LL i=1;i<=n;i++) {
        if (i == 1) {
            if (a[i] == 0) {
                for (LL j=1;j<=m;j++) dp[i][j] = 1;
            } else {
                dp[i][a[i]] = 1;
            }
        } else {
            if (a[i] == 0) {
                for (LL j=1;j<=m;j++) {
                    dp[i][j] = dp[i-1][j-1] + dp[i-1][j] + dp[i-1][j+1];
                    dp[i][j] %= MOD;
                }
            } else {
                dp[i][a[i]] = dp[i-1][a[i]-1] + dp[i-1][a[i]] + dp[i-1][a[i] + 1];
                dp[i][a[i]] %= MOD;
            }
        }
    }
    // for (LL i=1;i<=n;i++) {
    //     for (LL j=1;j<=m;j++) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    LL ans = 0;
    for (LL i=1;i<=m;i++) {
        ans += dp[n][i];
        ans %= MOD;
    }
    cout << ans << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}