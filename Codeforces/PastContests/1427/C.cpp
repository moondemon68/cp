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
    int r,n;
    cin >> r >> n;
    int t[n+5], x[n+5], y[n+5];
    t[0] = 0;
    x[0] = 1;
    y[0] = 1;
    for (int i=1;i<=n;i++) {
        cin >> t[i] >> x[i] >> y[i];
    }
    
    // n^2
    int dp[n+5];
    memset (dp,0,sizeof(dp));
    int maxdp[n+5];
    memset (maxdp,0,sizeof(maxdp));
    for (int i=1;i<=n;i++) {
        dp[i] = INT_MIN;
        maxdp[i] = INT_MIN;
    }
    for (int i=1;i<=n;i++) {
        for (int j=i-1;j>=0;j--) {
            int dist = abs(x[i]-x[j]) + abs(y[i]-y[j]);
            if (t[i]-t[j] > 2*r) {
                dp[i] = max(dp[i], maxdp[j] + 1);
                break;
            }
            if (t[i]-t[j] >= dist) dp[i] = max(dp[i], dp[j] + 1);
        }
        maxdp[i] = max(maxdp[i], maxdp[i-1]);
        maxdp[i] = max(maxdp[i], dp[i]);
    }
    // for (int i=0;i<=n;i++) cout << dp[i] << " ";
    cout << maxdp[n] << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
