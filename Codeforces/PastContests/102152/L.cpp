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
    LL n,m,h,w;
    cin >> n >> m >> h >> w;
    LL a[n+5][m+5], dp[n+5][m+5];
    memset (dp,0,sizeof(dp));
    for (LL i=1;i<=n;i++) {
        for (LL j=1;j<=m;j++) {
            cin >> a[i][j];
        }
    }
    for (LL i=1;i<=n;i++) {
        for (LL j=1;j<=m;j++) {
            dp[i][j] = dp[i-1][j] + a[i][j];
        }
    }
    for (LL i=1;i<=n;i++) {
        for (LL j=1;j<=m;j++) {
            dp[i][j] += dp[i][j-1];
        }
    }
    // for (LL i=1;i<=n;i++) {
    //     for (LL j=1;j<=m;j++) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    vector<pair<int,pii>> v;
    for (LL i=1;i<=n-h+1;i++) {
        for (LL j=1;j<=m-w+1;j++) {
            LL sum = dp[i+h-1][j+w-1]-dp[i-1][j+w-1]-dp[i+h-1][j-1]+dp[i-1][j-1];
            // cout << i << " " << j << " " << sum << endl;
            // if (sum <= ans) {
            //     ans = sum;
            //     x = i;
            //     y = j;
            // }
            v.pb(mp(sum, mp(i,j)));
        }
    }
    sort (v.begin(), v.end());
    int ans = INT_MAX;
    for (LL k=0;k<min((int)v.size(), 80);k++) {
        vector<int> p;
        int x = v[k].se.fi, y = v[k].se.se;
        for (LL i=x;i<=x+h-1;i++) {
            for (LL j=y;j<=y+w-1;j++) {
                p.pb(a[i][j]);
            }
        }
        sort (p.begin(), p.end());
        // for (LL i=0;i<v.size();i++) cout << v[i] << " ";
        // cout << endl;
        ans = min(ans, p[h*w/2]);
    }
    cout << ans << endl;
    
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}