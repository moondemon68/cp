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

LL a[5005];
LL dp[5005][5005];

LL solve(int l, int r) {
    if (l > r) return 0;
    if (l == r) return a[l];
    if (dp[l][r] != -1) return dp[l][r];
    LL ans = -1e13;
    ans = max(ans, min(solve(l+1, r-1), solve(l+2, r)) + a[l]);
    ans = max(ans, min(solve(l+1, r-1), solve(l, r-2)) + a[r]);
    return dp[l][r] = ans;
}

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for (int i=1;i<=n;i++) cin >> a[i];
    memset (dp,-1,sizeof(dp));
    cout << solve(1, n) << endl;
    // for (int i=1;i<=n;i++) {
    //     for (int j=1;j<=n;j++) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}