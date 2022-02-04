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
    LL tc;
    cin >> tc;
    while (tc--) {
        LL n, k;
        cin >> n >> k;
        string a[n+5];
        for (LL i=1;i<=n;i++) cin >> a[i];
        set<string> s;
        LL dp[n+5];
        memset(dp,0,sizeof(dp));
        dp[1] = 1;
        map<string, int> last;
        for (LL i=1;i<=n;i++) {
            dp[i+k+1] = (dp[i] * 2) % MOD;
            for (LL j=i+1;j<=i+k;j++) {
                dp[i+k+1] += dp[j];
                dp[i+k+1] %= MOD;
            }
            if (last[a[i]] > 0) dp[i+k+1] -= dp[last[a[i]]];
            dp[i+k+1] %= MOD;
            last[a[i]] = i;
        }
        // LL ans = 0;
        // for (LL i=1;i<=n;i++) {
        //     ans += dp[i];
        //     ans %= MOD;
        // }
        for (LL i=1;i<=n+k+1;i++) cout << dp[i] << " ";
        cout << endl;
        cout << dp[n+k+1] << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
/*
1
7 0
a b b a c a a
1 2 4 6 11 22 38 53 

1
7 1
a b b a c a a
*/