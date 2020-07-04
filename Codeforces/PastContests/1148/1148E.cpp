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
    LL n;
    cin >> n;
    LL b[n+5], tot = 0;
    pii a[n+5];
    for (LL i=1;i<=n;i++) {
        cin >> a[i].fi;
        a[i].se = i;
        tot += a[i].fi;
    }
    for (LL i=1;i<=n;i++) {
        cin >> b[i];
        tot -= b[i];
    }
    sort (a+1,a+n+1);
    sort (b+1,b+n+1);
    if (tot != 0) {
        cout << "NO" << endl;
        return 0;
    }
    LL d[n+5];
    for (LL i=1;i<=n;i++) d[i] = b[i]-a[i].fi;
    LL p = 0;
    for (LL i=1;i<=n;i++) {
        p += d[i];
        if (p < 0) {
            cout << "NO" << endl;
            return 0;
        }
    }
    stack<pii> s;
    vector<LL> ansa, ansb, ansc;
    for (LL i=1;i<=n;i++) {
        if (d[i] == 0) continue;
        if (d[i] > 0) {
            s.push({d[i], a[i].se});
        } else {
            d[i] *= -1;
            while (d[i] > 0) {
                pii cur = s.top();
                s.pop();
                LL mov = min(cur.fi, d[i]);
                ansa.pb(cur.se);
                ansb.pb(a[i].se);
                ansc.pb(mov);
                cur.fi -= mov;
                d[i] -= mov;
                if (cur.fi > 0) {
                    s.push(cur);
                }
            }
        }
    }
    cout << "YES" << endl;
    cout << ansa.size() << endl;
    for (LL i=0;i<ansa.size();i++) {
        cout << ansa[i] << " " << ansb[i] << " " << ansc[i] << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}