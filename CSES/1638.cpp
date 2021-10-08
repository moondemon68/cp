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
    char a[n+5][n+5];
    for (int i=1;i<=n;i++) {
        string s;
        cin >> s;
        for (int j=1;j<=n;j++) {
            a[i][j] = s[j-1];
        }
    }
    LL dp[n+5][n+5];
    memset (dp,0,sizeof(dp));
    if (a[1][1] == '.') dp[1][1] = 1;
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=n;j++) {
            if (i == 1 && j == 1) continue;
            if (a[i][j] == '*') continue;
            if (i >= 2) dp[i][j] += dp[i-1][j];
            if (j >= 2) dp[i][j] += dp[i][j-1];
            dp[i][j] %= MOD;
        }
    }
    // for (int i=1;i<=n;i++) {
    //     for (int j=1;j<=n;j++) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    cout << dp[n][n] << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}