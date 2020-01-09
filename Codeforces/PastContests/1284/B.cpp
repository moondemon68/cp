#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<LL,LL>
#define LL long long
using namespace std;

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    LL n;
    cin >> n;
    pii a[n+5];
    vector<LL> v[n+5];
    for (LL i=1;i<=n;i++) {
        LL k;
        cin >> k;
        LL x;
        cin >> x;
        v[i].pb(x);
        a[i].fi = x;
        for (LL j=2;j<=k;j++) {
            cin >> x;
            v[i].pb(x);
            a[i].se = x;
        }
        if (k == 1) a[i].se = a[i].fi;
    }
    vector<pii> p;
    for (LL i=1;i<=n;i++) {
        bool dec = 1;
        for (LL j=0;j<v[i].size()-1;j++) {
            if (v[i][j] < v[i][j+1]) {
                dec = 0;
                break;
            }
        }
        if (dec) {
            p.pb(a[i]);
        }
    }
    sort (p.begin(), p.end());
    reverse (p.begin(), p.end());
    // for (LL i=0;i<p.size();i++) cout << p[i].fi << ' ' << p[i].se << endl;
    LL ans = 0;
    for (LL i=0;i<p.size();i++) {
        LL l = 0, r = p.size()-1, cnt = p.size();
        while (l <= r) {
            LL m = (l + r) / 2;
            if (p[m].fi > p[i].se) {
                l = m + 1;
            } else {
                r = m - 1;
                cnt = m;
            }
        }
        // cout << p.size()-cnt << " ";
        ans += p.size()-cnt;
    }
    // cout << ans << endl;
    cout << n*n - ans << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}