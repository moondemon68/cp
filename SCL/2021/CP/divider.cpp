#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define INF 123456789875642310
#define pii pair<LL,LL>
#define LL long long
using namespace std;

LL dp[10005][105];
LL a[10005];
LL n;

LL solve(LL l, LL rem) {
    if (rem == 0) return dp[l][rem] = (n - l + 1) * (a[n] - a[l-1]);
    if (rem < 0) return 0;
    if (dp[l][rem] != INF) return dp[l][rem];
    LL ret = INF;
    for (LL i=l;i<n;i++) {
        LL cost = (i - l + 1) * (a[i] - a[l - 1]) + solve(i + 1, rem - 1);
        ret = min(ret, cost);
    }
    // cout << l << " " << rem << " " << ret << endl;
    // if (ret == INF) ret = 0;
    return dp[l][rem] = ret;
}

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    LL k;
    cin >> n >> k;
    for (LL i=1;i<=n;i++) cin >> a[i];
    for (LL i=1;i<=n;i++) {
        for (LL j=0;j<k;j++) dp[i][j] = INF;
    }
    for (LL i=2;i<=n;i++) a[i] += a[i-1];
    cout << solve(1, k - 1) << endl;
    // for (LL i=1;i<=n;i++) {
    //     for (LL j=0;j<k;j++) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}