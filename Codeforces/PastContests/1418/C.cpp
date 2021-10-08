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
        int a[n+5];
        for (int i=1;i<=n;i++) cin >> a[i];
        // int dp[n+5];
        // for (int i=1;i<=n;i++) dp[i] = INF;
        // dp[1] = a[1];
        // dp[2] = a[1] + a[2];
        // bool y = 0;
        // for (int i=2;i<=n;i++) {
        //     if (!y) {
        //         if (i > 2) dp[i] = min(dp[i], dp[i-2]);
        //         dp[i] = min(dp[i], dp[i-1]);
        //     } else {
        //         if (i > 2) dp[i] = min(dp[i], dp[i-2] + a[i-1] + a[i-2]);
        //         dp[i] = min(dp[i], dp[i-1] + a[i-1]);
        //     }
        //     y = !y;
        // }
        // for (int i=1;i<=n;i++) cout << dp[i] << " ";
        // cout << dp[n] << endl;
        int ans = 0, cnt = 0;
        a[n+1] = 0;
        if (a[1] == 1) ans++;
        for (int i=2;i<=n+1;i++) {
            if (a[i] == 0) {
                ans += cnt/3;
                cnt = 0;
            } else {
                cnt++;
            }
        }
        cout << ans << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}