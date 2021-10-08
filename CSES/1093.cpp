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
    int n;
    cin >> n;
    if (n * (n+1) % 4 != 0) {
        cout << 0 << endl;
        return 0;
    }
    int target = n * (n+1) / 4;
    LL dp[505][target+5];
    memset (dp,0,sizeof(dp));
    dp[0][0] = 1;
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=target;j++) {
            if (j - i >= 0) {
                dp[i][j] += dp[i-1][j-i] + dp[i-1][j];
            } else {
                dp[i][j] += dp[i-1][j];
            }
            dp[i][j] %= MOD;
        }
    }
    // for (int i=1;i<=n;i++) {
    //     for (int j=1;j<=target;j++) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    cout << dp[n][target] << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}