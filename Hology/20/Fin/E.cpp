#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fi first
#define se second
using ll = long long;
using pii = pair<ll, ll>;
using pll = pair<ll, ll>;

const ll N = 1e5 + 5;
ll par[N][25];
ll dep[N], dist[N], new_dist[25][N];
vector<pii> adj[N];
bool vis[N];
set<pii> edges; // buat ngebuang pas bikin mst
ll n, m;

void dfs(ll u) {
    vis[u] = true;
    for (ll i = 1; i <= 18; i++) {
        par[u][i] = par[par[u][i - 1]][i - 1];
    }
    for (auto nxt: adj[u]) {
        ll v = nxt.fi;
        ll w = nxt.se;
        if (vis[v]) continue;
        dist[v] = dist[u] + w;
        dep[v] = dep[u] + 1;
        par[v][0] = u;
        pii edge = {min(u, v), max(u, v)};
        edges.erase(edge);
        dfs(v);
    }
}

ll lca(ll u, ll v) {
    if (dep[u] > dep[v]) swap(u, v);
    ll del = dep[v] - dep[u];
    for (ll i = 18; i >= 0; i--) {
        if (del >> i & 1) v = par[v][i];
    }
    if (u == v) return u;
    for (ll i = 18; i >= 0; i--) {
        if (par[u][i] != par[v][i]) {
            u = par[u][i];
            v = par[v][i];
        }
    }
    return par[u][0];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (ll i = 0; i < m; i++) {
        ll u, v, w;
        cin >> u >> v >> w;
        adj[u].pb({v, w});
        adj[v].pb({u, w});
        pii edge = {min(u, v), max(u, v)};
        edges.insert(edge);
    }
    dfs(1);
    ll sisa = edges.size();
    vector<pii> nedges;
    nedges.pb({-1, -1});
    for (auto edge: edges) nedges.pb(edge);
    for (ll sis = 1; sis <= sisa; sis++) {
        for (ll i = 1; i <= n; i++) {
            new_dist[sis][i] = 1e18;
        }
        ll u = nedges[sis].fi;
        new_dist[sis][u] = 0;

        priority_queue<pll, vector<pll>, greater<pll>> pq;
        pq.push({0ll, u});
        while (!pq.empty()) {
            pii nxt = pq.top();
            pq.pop();
            ll w = nxt.fi, v = nxt.se;
            if (new_dist[sis][v] != w) continue;
            for (auto nx: adj[v]) {
                if (w + nx.se < new_dist[sis][nx.fi]) {
                    new_dist[sis][nx.fi] = w + nx.se;
                    pq.push({new_dist[sis][nx.fi], nx.fi});
                }
            }
        }
    }

    ll q;
    cin >> q;
    while (q--) {
        ll u, v;
        cin >> u >> v;
        ll lcuv = lca(u, v);
        ll ans = dist[u] + dist[v] - 2 * dist[lcuv];
        for (ll sis = 1; sis <= sisa; sis++) {
            ans = min(ans, new_dist[sis][u] + new_dist[sis][v]);
        }
        cout << ans << '\n';
    }
    return 0;
}