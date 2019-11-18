#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<LL,LL>
#define LL long long
using namespace std;

bool cmp(pii a, pii b) {
    if (a.fi==b.fi) return a.se>b.se;
    else return a.fi<b.fi;
}

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    LL n;
    cin >> n;
    pii a[n+5];
    for (LL i=1;i<=n;i++) cin >> a[i].fi >> a[i].se;
    sort (a+1,a+n+1, cmp);
    map<LL,LL> m;
    set<LL> s;
    for (LL i=2;i<=n;i++) {
        m[a[i].se]++;
        s.insert(a[i].se);
    }
    LL minx = a[1].se;
    LL ans = minx - a[1].fi + 1 + *s.begin() - a[n].fi + 1;
    //cout << ans << endl;
    for (LL i=2;i<n;i++) {
        minx = min(minx, a[i].se);
        s.erase(a[i].se);
        m[a[i].se]--;
        if (m[a[i].se] > 0) s.insert(a[i].se);
        ans = max(ans, minx - a[i].fi + 1 + *s.begin() - a[n].fi + 1);
        //cout << minx - a[i].fi + 1 + *s.begin() - a[n].fi + 1 << endl;
    }
    cout << ans << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}