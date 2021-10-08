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

bool cmp (pair<pii,LL> a, pair<pii,LL> b) {
    return a.fi.se < b.fi.se;
}

LL dp[500005];

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    LL n;
    cin >> n;
    pair<pii, LL> a[n+5];
    for (LL i=1;i<=n;i++) cin >> a[i].fi.fi >> a[i].fi.se >> a[i].se;
    sort (a+1,a+n+1,cmp);
    // for (LL i=1;i<=n;i++) cout << a[i].fi.fi << a[i].fi.se << a[i].se << endl;

    memset (dp,0,sizeof(dp));
    for (LL i=1;i<=n;i++) {
        LL res = a[i].se;
        LL l = 1, r = i, ans = 0;
        while (l <= r) {
            LL m = (l+r)/2;
            if (a[m].fi.se+1 <= a[i].fi.fi) {
                ans = m;
                l = m+1;
            } else {
                r = m-1;
            }
        }
        if (ans != 0) res += dp[ans];
        dp[i] = max(dp[i-1], res);
    }
    // for (LL i=1;i<=n;i++) cout << dp[i] << " ";
    cout << dp[n] << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}