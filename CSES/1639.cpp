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
    string s,t;
    cin >> s >> t;
    int n = s.size(), m = t.size();
    int dp[n+5][m+5];
    for (int i=0;i<=n;i++) {
        for (int j=0;j<=m;j++) {
            dp[i][j] = MOD;
        }
    }
    dp[0][0] = 0;
    for (int i=0;i<=n;i++) {
        for (int j=0;j<=m;j++) {
            if (i >= 1) dp[i][j] = min(dp[i][j], dp[i-1][j] + 1);
            if (j >= 1) dp[i][j] = min(dp[i][j], dp[i][j-1] + 1);
            if (i >= 1 && j >= 1) dp[i][j] = min(dp[i][j], dp[i-1][j-1] + (s[i-1] == t[j-1] ? 0 : 1));
        }
    }
    // for (int i=1;i<=n;i++) {
    //     for (int j=1;j<=m;j++) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    cout << dp[n][m] << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}