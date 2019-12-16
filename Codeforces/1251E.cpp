#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
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
        pii a[n+5];
        for (int i=1;i<=n;i++) cin >> a[i].fi >> a[i].se;
        sort (a+1,a+n+1);
        int dp[n+5][n+5];
        for (int i=0;i<=n;i++) for (int j=0;j<=n;j++) dp[i][j]=INT_MAX/4;
        dp[0][0]=0;
        for (int i=0;i<=n;i++) {
            for (int j=0;j<=n;j++) {
                if (j>=a[i].fi) dp[i+1][j]=min(dp[i+1][j], dp[i][j]);
                else {
                    dp[i+1][j+1] = min(dp[i+1][j+1], dp[i][j]+a[i].se);
                    dp[i+1][j] = dp[i][j];
                }
            }
        }
        for (int i=0;i<=n;i++) {
            for (int j=0;j<=n;j++) {
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}