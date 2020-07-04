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
    LL n,k;
    cin >> n >> k;
    LL t[n+5], a[n+5], b[n+5];
    for (LL i=1;i<=n;i++) cin >> t[i] >> a[i] >> b[i];
    vector<LL> p,q,r,s;
    for (LL i=1;i<=n;i++) {
        if (a[i] == 1 && b[i] == 1) p.pb(t[i]);
        else if (a[i] == 1) q.pb(t[i]);
        else if (b[i] == 1) r.pb(t[i]);
    }
    if ((p.size() + min(q.size(), r.size())) < k) {
        cout << -1 << endl;
        return 0;
    }
    p.pb(0);
    s.pb(0);
    sort (p.begin(), p.end());
    sort (q.begin(), q.end());
    sort (r.begin(), r.end());
    for (LL i=0;i<min(q.size(), r.size());i++) s.pb(q[i]+r[i]);
    sort (s.begin(), s.end());

    for (LL i=1;i<p.size();i++) p[i] += p[i-1];
    for (LL i=1;i<s.size();i++) s[i] += s[i-1];

    LL ssz = s.size();
    LL psz = p.size();
    LL ans = INT_MAX;
    for (LL i=0;i<=k;i++) {
        if (i < psz && i >= 0 && (k-i) < ssz && (k-i) >= 0) ans = min(ans, p[i]+s[k-i]);
    }
    cout << ans << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}