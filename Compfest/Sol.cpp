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

LL pset[100005], m, n;
vector< pair<pii, LL> > edge;
void init() {
    for (LL i=1;i<=n;i++) pset[i] = i;
}
LL findSet(LL u) {
    return pset[u] == u ? u : pset[u] = findSet(pset[u]);
}
LL isSameSet(LL u, LL v) {
    // cout << findSet(u) << ' ' << findSet(v) << endl;
    return findSet(u) == findSet(v);
}
void unionSet(LL u, LL v) {
    pset[findSet(u)] = findSet(v);
}

bool cmp(pair<pii,LL> a, pair<pii,LL> b) {
    return a.se < b.se;
}

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    LL tc;
    tc = 1;
    while (tc--) {
        cin >> n >> m;

        init();

        for (LL i=1;i<=m;i++) {
            LL u,v,w;
            cin >> u >> v >> w;
            // if (isSameSet(u, v)) continue;
            // unionSet(u,v);
            edge.pb({{u, v}, w});
        }
        sort (edge.begin(), edge.end(), cmp);
        
        LL ans = 0;

        for (LL i=0;i<edge.size();i++) {
            if (isSameSet(edge[i].fi.fi, edge[i].fi.se)) continue;
            unionSet(edge[i].fi.fi, edge[i].fi.se);
            ans += edge[i].se;
        }

        cout << ans << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}