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

int col[1000005];
int dp[1000005][8];

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m;
    cin >> n >> m;
    int a[n+5][m+5];
    for (int i=1;i<=n;i++) {
        string s;
        cin >> s;
        for (int j=1;j<=m;j++) {
            a[i][j] = s[j-1]-'0';
        }
    }
    if (n == 1) {
        cout << 0 << endl;
        return 0;
    }
    if (n > 3) {
        cout << -1 << endl;
        return 0;
    }
    for (int i=1;i<=m;i++) {
        col[i] = 0;
        for (int j=n;j>=1;j--) {
            col[i] += a[j][i];
            col[i] *= 2;
        }
        col[i] /= 2;
    }

    bool can[8][8];
    memset (can,1,sizeof(can));
    for (int i=0;i<8;i++) {
        for (int j=0;j<8;j++) {
            int x = ((i&(1<<0)) != 0) + ((i&(1<<1)) != 0) + ((j&(1<<0)) != 0) + ((j&(1<<1)) != 0);
            if (x%2 == 0) can[i][j] = 0;
            if (n == 3) {
                x = ((i&(1<<1)) != 0) + ((i&(1<<2)) != 0) + ((j&(1<<1)) != 0) + ((j&(1<<2)) != 0);
                if (x%2 == 0) can[i][j] = 0;
            }
        }
    }

    memset (dp,0,sizeof(dp));
    for (int i=1;i<=m;i++) {
        int mask = col[i];
        for (int j=0;j<(1<<n);j++) {
            dp[i][j] = INT_MAX;
            for (int k=0;k<(1<<n);k++) {
                if (can[j][k]) {
                    // if (i == 3) cout << j << k << " ";
                    int x = j^mask;
                    dp[i][j] = min(dp[i][j], dp[i-1][k] + __builtin_popcount(x));
                }
            }
        }
    }
    int ans = INT_MAX;
    for (int i=0;i<(1<<n);i++) {
        ans = min(ans, dp[m][i]);
    }
    cout << ans << endl;
    // for (int i=1;i<=m;i++) {
    //     for (int j=0;j<(1<<n);j++) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}