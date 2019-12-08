#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define LL long long
using namespace std;

int dp[3005][3005];
pii a[3005];

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,t;
    cin >> n >> t;
    for (int i=0;i<n;i++) cin >> a[i].fi >> a[i].se;
    sort (a,a+n);
    for (int i=0;i<=n;i++) {
        for (int j=0;j<=t;j++) {
            if (i==0||j==0) dp[i][j]=0;
            else if (a[i-1].fi <= j) dp[i][j] = max(a[i-1].se + dp[i-1][j-a[i-1].fi], dp[i-1][j]);
            else dp[i][j] = dp[i-1][j];
        }
    }
    int ans=0;
    for (int i=0;i<n;i++) {
        ans = max(ans, dp[i][t-1] + a[i].se);
    }
    cout << ans << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}