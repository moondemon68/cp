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
    LL n;
    cin >> n;
    LL a[4][n+5];
    for (LL i=1;i<=3;i++) {
        for (LL j=1;j<=n;j++) {
            cin >> a[i][j];
        }
    }

    LL dp[n+5][5];
    for (LL i=0;i<=n+1;i++) {
        for (LL j=1;j<=3;j++) {
            dp[i][j] = (LL)INT_MIN * (LL)INT_MIN * (LL)-1;
        }
    }
    dp[1][1] = 0;

    // 10 10 10 -1 -1
    // -1 10 10 10 10
    // -1 10 10 10 10

    for (LL i=1;i<=n;i++) {
        dp[i+1][1] = max(dp[i+1][1], dp[i][1] + a[1][i]);
        dp[i+1][1] = max(dp[i+1][1], dp[i][2] + a[2][i] + a[1][i]);
        dp[i+1][1] = max(dp[i+1][1], dp[i][3] + a[3][i] + a[2][i] + a[1][i]);
        dp[i+1][2] = max(dp[i+1][2], dp[i][1] + a[1][i] + a[2][i]);
        dp[i+1][2] = max(dp[i+1][2], dp[i][2] + a[2][i]);
        dp[i+1][2] = max(dp[i+1][2], dp[i][3] + a[3][i] + a[2][i]);
        dp[i+1][3] = max(dp[i+1][3], dp[i][1] + a[1][i] + a[2][i] + a[3][i]);
        dp[i+1][3] = max(dp[i+1][3], dp[i][2] + a[2][i] + a[3][i]);
        dp[i+1][3] = max(dp[i+1][3], dp[i][3] + a[3][i]);
        // spiral
        dp[i+2][1] = max(dp[i+2][1], dp[i][3] + a[1][i] + a[2][i] + a[3][i] + a[1][i+1] + a[2][i+1] + a[3][i+1]);
        dp[i+2][3] = max(dp[i+2][3], dp[i][1] + a[1][i] + a[2][i] + a[3][i] + a[1][i+1] + a[2][i+1] + a[3][i+1]);
    }

// for (int i=1;i<=3;i++) {
//     for (int j=1;j<=n+1;j++) {
//         cout << dp[j][i] << " ";
//     }
//     cout << endl;
// }
    cout << dp[n+1][3] << endl;

    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}