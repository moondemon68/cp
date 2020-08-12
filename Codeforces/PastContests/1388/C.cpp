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

bool vis[100005];
LL sz[100005];
vector<LL> adj[100005];
LL p[100005];
LL par[100005];

LL dfs(LL x) {
    LL cnt = p[x];
    vis[x] = 1;
    for (auto next : adj[x]) {
        if (vis[next]) continue;
        par[next] = x;
        cnt += dfs(next);
    }
    return sz[x] = cnt;
}

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    LL tc;
    cin >> tc;
    while (tc--) {
        LL n,m;
        cin >> n >> m;
        for (LL i=1;i<=n;i++) cin >> p[i];
        LL h[n+5];
        for (LL i=1;i<=n;i++) cin >> h[i];
        for (LL i=1;i<n;i++) {
            LL x,y;
            cin >> x >> y;
            adj[x].pb(y);
            adj[y].pb(x);
        }
        memset (sz,0,n+5);
        memset (vis,0,n+5);
        dfs(1);
        pii a[n+5];
        bool y = 1;
        for (LL i=1;i<=n;i++) {
            if ((sz[i]+h[i]) % 2 == 1) y = 0;
            a[i].fi = (sz[i]+h[i]) / 2; // happy
            a[i].se = (sz[i]-h[i]) / 2; // sad
            if (a[i].fi < 0) y = 0;
            if (a[i].fi > sz[i]) y = 0;
            if (a[i].se < 0) y = 0;
            if (a[i].se > sz[i]) y = 0;
            if (a[i].fi - a[i].se != h[i]) y = 0;
        }
        for (LL i=1;i<=n;i++) {
            LL cnt = 0;
            for (auto next : adj[i]) {
                if(par[next] == i) cnt += a[next].fi;
            }
            // cout << cnt << " ";
            if (cnt > a[i].fi) {
                y = 0;
            }
        }
        // for (LL i=1;i<=n;i++) cout << sz[i] << " " << a[i].fi << " " << a[i].se << endl;
        // cout << endl;
        for (LL i=1;i<=n;i++) adj[i].clear();
        if (y) cout << "YES"; else cout << "NO";
        cout << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}