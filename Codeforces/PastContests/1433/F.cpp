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

bool cmp(int a, int b) {
    return a > b;
}

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m,k;
    cin >> n >> m >> k;
    int a[n+5][m+5];
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=m;j++) cin >> a[i][j];
    }

    int dp[n+5][m+5][m/2+5][k+5];
    for (int i=1;i<=n+1;i++) {
        for (int j=1;j<=m+1;j++) {
            for (int t=0;t<=m/2;t++) {
                for (int r=0;r<k;r++) {
                    if (i == 1 && j == 1 && t == 0 && r == 0) dp[i][j][t][r] = 0;
                    else dp[i][j][t][r] = -1;
                }
            }
        }
    }
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=m;j++) {
            for (int t=0;t<=m/2;t++) {
                for (int r=0;r<k;r++) {
                    if (dp[i][j][t][r] == -1) continue;
                    if (j == m) {
                        dp[i+1][1][0][r] = max(dp[i+1][1][0][r], dp[i][j][t][r]);
                    } else {
                        dp[i][j+1][t][r] = max(dp[i][j+1][t][r], dp[i][j][t][r]);
                    }
                    if (t < m/2) {
                        if (j == m) {
                            dp[i+1][1][0][(r+a[i][j]) % k] = max(dp[i+1][1][0][(r+a[i][j]) % k], dp[i][j][t][r] + a[i][j]); 
                        } else {
                            dp[i][j+1][t+1][(r+a[i][j])%k] = max(dp[i][j][t+1][(r+a[i][j])%k], dp[i][j][t][r] + a[i][j]);
                        }
                    }
                }
            }
        }
    }
    int ans = max(0, dp[n+1][1][0][0]);
    cout << ans << endl;
    // for (int i=1;i<=n+1;i++) {
    //     for (int j=1;j<=m;j++) {
    //         cout << dp[i][j][0][0] << " ";
    //     }
    //     cout << endl;
    // }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}