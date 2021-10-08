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

bool cmp(pii a, pii b) {
    return a.se < b.se;
}

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    LL n;
    cin >> n;
    vector<pii> v;
    for (LL i=1;i<=n;i++) {
        LL a, t;
        cin >> a >> t;
        v.pb({a, t});
    }
    LL q;
    cin >> q;
    pii a[n+5];
    for (LL i=1;i<=q;i++) {
        cin >> a[i].fi;
        a[i].se = i;
    }
    sort(a+1,a+q+1);
    LL l = 1, r = q;
    LL cur = 0;
    for (auto x : v) {
        if (x.se == 1) {
            cur += x.fi;
        } else if (x.se == 2) {
            while (a[l].fi + cur < x.fi) {
                l++;
            }
        } else {
            while (a[r].fi + cur > x.fi) {
                r--;
            }
        }
        // cout << l << " " << r << " " << a[l].fi + cur << " " << a[r].fi + cur << endl;
    }
    // cout << l << " " << r << endl;
    for (LL i = 1; i <= q; i++) {
        if (i <= l) a[i].fi = a[l].fi;
        if (i >= r) a[i].fi = a[r].fi;
    }
    sort(a+1,a+q+1, cmp);
    for (LL i = 1; i <= q; i++) cout << a[i].fi + cur << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}