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
    LL n,m;
    cin >> n >> m;
    LL a[n+5], b[n+5];
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    for (LL i=1;i<=n;i++) {
        cin >> a[i];
    }
    for (LL i=1;i<=n;i++) cin >> b[i];
    sort (a+1,a+n+1);
    sort (b+1,b+n+1);
    a[n+1] = -2;
    b[n+1] = -2;
    vector<pii> p;
    LL cnt = 1;
    for (LL i=1;i<=n;i++) {
        if (a[i] == a[i+1]) cnt++;
        else {
            p.pb(mp(a[i], cnt));
            cnt = 1;
        }
    }
    vector<pii> q;
    for (LL i=0;i<p.size();i++) q.pb(p[i]);
    for (LL i=0;i<p.size();i++) q.pb(p[i]);
    vector<pii> r;
    cnt = 1;
    for (LL i=1;i<=n;i++) {
        if (b[i] == b[i+1]) cnt++;
        else {
            r.pb(mp(b[i], cnt));
            cnt = 1;
        }
    }
    // for (LL i=0;i<q.size();i++) cout << q[i].fi << " " << q[i].se << endl;
    // cout << "PLA" << endl;
    // for (LL i=0;i<r.size();i++) cout << r[i].fi << " " << r[i].se << endl;
    // cout << "PLA" << endl;
    LL ans = MOD;
    for (LL i=0;i<q.size() - r.size();i++) {
        LL d = -1, y = 1;
        for (LL j=0;j<r.size();j++) {
            if (j == 0) d = r[j].fi - q[i+j].fi;
            if (r[j].se != q[i+j].se) {
                y = 0;
                break;
            }
        }
        if (d < 0) d += m;
        //cout << y << " " << d << endl;
        for (LL j=0;j<r.size();j++) {
            //cout << r[j].fi << " ";
            if ((r[j].fi) % m != (q[i+j].fi + d) % m) y = 0;
        }
        if (y == 1) ans = min(ans, d);
    }
    cout << ans << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}