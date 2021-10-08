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
    int n,x;
    cin >> n >> x;
    int h[n+5], s[n+5];
    for (int i=1;i<=n;i++) cin >> h[i];
    for (int i=1;i<=n;i++) cin >> s[i];
    int dp[n+5][x+5];
    memset (dp,0,sizeof(dp));
    for (int i=1;i<=n;i++) {
        for (int j=0;j<=x;j++) {
            if (j - h[i] >= 0) dp[i][j] = max(dp[i-1][j], dp[i-1][j-h[i]] + s[i]);
            else dp[i][j] = dp[i-1][j];
        }
    }
    cout << dp[n][x] << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}