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

const LL MAXN = 1000;
LL a[MAXN+5][MAXN+5];
LL dp[MAXN+5][MAXN+5];
LL dp2[MAXN+5][MAXN+5];

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    LL n;
    cin >> n;
    for (LL i=1;i<=n;i++) {
        string s;
        cin >> s;
        for (LL j=1;j<=n;j++) {
            a[i][j] = s[j-1] - '0';
        }
    }
    memset(dp,0,sizeof(dp));
    dp[1][1] = a[1][1];
    for (LL i=1;i<=n;i++) {
        for (LL j=1;j<=n;j++) {
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]) + a[i][j];
        }
    }
    dp2[1][1] = 1;
    for (LL i=1;i<=n;i++) dp2[i][1] = 1;
    for (LL i=1;i<=n;i++) dp2[1][i] = 1;
    for (LL i=2;i<=n;i++) {
        for (LL j=2;j<=n;j++) {
            dp2[i][j] = 0;
            if (dp[i-1][j] + a[i][j] == dp[i][j]) dp2[i][j] += dp2[i-1][j];
            if (dp[i][j-1] + a[i][j] == dp[i][j]) dp2[i][j] += dp2[i][j-1];
            dp2[i][j] %= MOD;
        }
    }
    // for (LL i=1;i<=n;i++) {
    //     for (LL j=1;j<=n;j++) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    cout << dp[n][n] % MOD << " " << dp2[n][n] % MOD << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}