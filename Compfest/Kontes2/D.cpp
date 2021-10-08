#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define INF 1234567890
#define pii pair<int,int>
#define LL long long
using namespace std;

int pset[50005], m, n, x;
vector< pair<int, pii> > edge;
void init() {
    for (int i=1;i<=n;i++) pset[i] = i;
}
int findSet(int u) {
    return pset[u] == u ? u : pset[u] = findSet(pset[u]);
}
int isSameSet(int u, int v) {
    // cout << findSet(u) << ' ' << findSet(v) << endl;
    return findSet(u) == findSet(v);
}
void unionSet(int u, int v) {
    pset[findSet(u)] = findSet(v);
}

vector<LL> adj[50005];
LL par[50005];
LL sz[50005];
bool vis[50005];

LL dfs(LL cur) {
    LL cnt = 1;
    vis[cur] = 1;
    for (auto x : adj[cur]) {
        if (vis[x]) continue;
        cnt += dfs(x);
        par[x] = cur;
    }
    return sz[cur] = cnt;
}

LL fpow(LL a, LL b) {
    LL ans = 1;
    while (b) {
        if (b & 1) {
            ans *= a;
            ans %= MOD;
        }
        a *= a;
        a %= MOD;
        b >>= 1;
    }
    return ans;
}

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc;
    cin >> tc;
    while (tc--) {
        cin >> n >> m >> x;

        for (LL i=1;i<=n;i++) {
            adj[i].clear();
            par[i] = -1;
            sz[i] = -1;
            vis[i] = 0;
        }
        init();
        map<pii, int> weight;

        for (int i=1;i<=m;i++) {
            int u,v,w;
            cin >> u >> v;
            w = i-1;
            // cout << isSameSet(u,v) << endl;
            if (isSameSet(u, v)) continue;
            unionSet(u,v);
            adj[u].pb(v);
            adj[v].pb(u);
            weight[{u,v}] = w;
            weight[{v,u}] = w;
        }

        dfs(1);

        // for (LL i=1;i<=n;i++) cout << par[i] << " ";
        // cout << endl;
        // for (LL i=1;i<=n;i++) cout << sz[i] << " ";
        // cout << endl;

        LL ans = 0;
        for (LL i=2;i<=n;i++) {
            ans += (((n-sz[i]) * sz[i]) % MOD) * ((fpow(2, weight[{i,par[i]}]) * x) % MOD);
            ans %= MOD;
        }
        cout << ans << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}