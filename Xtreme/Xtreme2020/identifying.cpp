#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pb push_back
#define sz(a) (int)(a).size()
#define mp(a, b) make_pair((a), (b))
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;

const ll MOD = 1e9 + 7;
const ll INF = 1e18;
const ll IINF = INT_MAX;

int n, m; // number of nodes
vector<vector<int>> adj; // adjacency list of graph
vector<vector<int>> nadj; // adjacency list of graph
vector<bool> is_cutpoint;
vector<bool> visited;
vector<int> tin, low;
vector<int> par, sz;
int timer;

void dfs(int v, int p = -1) {
    visited[v] = true;
    tin[v] = low[v] = timer++;
    int children=0;
    for (int to : adj[v]) {
        if (to == p) continue;
        if (visited[to]) {
            low[v] = min(low[v], tin[to]);
        } else {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] >= tin[v] && p!=-1)
                is_cutpoint[v] = true;
            ++children;
        }
    }
    if(p == -1 && children > 1)
        is_cutpoint[v] = true;
}

void find_cutpoints() {
    timer = 0;
    visited.assign(n + 1, false);
    tin.assign(n + 1, -1);
    low.assign(n + 1, -1);
    for (int i = 1; i <= n; ++i) {
        if (!visited[i])
            dfs (i);
    }
}

int find(int x) {
    return par[x] == x ? x : par[x] = find(par[x]);
}

void make(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v) return;
    if (sz[u] < sz[v]) swap(u, v);
    sz[u] += sz[v];
    par[v] = u;
}


void init() {
    par.resize(n + 1);
    sz.resize(n + 1);
    adj.resize(n + 1);
    nadj.resize(n + 1);
    visited.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        par[i] = i;
        sz[i] = 1;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    
    is_cutpoint.resize(n + 1);
    init();
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
        make(u, v);
    }
    find_cutpoints();
    // for (int i = 1; i <= n; i++) {
    //     if (is_cutpoint[i]) cout << i << ' ';
    // }
    // cout << '\n';
    int q;
    cin >> q;
    while (q--) {
        int a, b;
        cin >> a >> b;
        for (int i = 1; i <= n; i++) {
            nadj[i].clear();
        }
        for (int u = 1; u <= n; u++) {
            for (auto v: adj[u]) {
                if (find(u) == find(a) && find(v) == find(a)) {
                    nadj[u].pb(v);
                }
            }
        }
        vector<int> cutpoints;
        for (int i = 1; i <= n; i++) {
            if (is_cutpoint[i] && find(i) == find(a)) cutpoints.pb(i);
        }
        vector<bool> fix(n + 1, false);
        for (auto cut: cutpoints) {
            vector<int> color(n + 1, -1);
            for (int u = a; u <= a; u++) {
                if (color[u] == -1) {
                    stack<int> s;
                    s.push(u);
                    color[u] = u;
                    while (!s.empty()) {
                        int cur = s.top();
                        s.pop();
                        for (auto v : nadj[cur]) {
                            if (color[v] == -1 && v != cut) {
                                color[v] = u;
                                s.push(v);
                            }
                        }
                    }
                }
            }
            if (color[a] != color[b]) {
                fix[cut] = true;
            }
        }
        fix[a] = fix[b] = true;
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (fix[i]) {
                ans++;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}