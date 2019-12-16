#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define LL long long
using namespace std;

struct FlowEdge {
    int v, u;
    long long cap, flow = 0;
    FlowEdge(int v, int u, long long cap) : v(v), u(u), cap(cap) {}
};

struct Dinic {
    const long long flow_inf = 1e18;
    vector<FlowEdge> edges;
    vector<vector<int>> adj;
    int n, m = 0;
    int s, t;
    vector<int> level, ptr;
    queue<int> q;

    Dinic(int n, int s, int t) : n(n), s(s), t(t) {
        adj.resize(n);
        level.resize(n);
        ptr.resize(n);
    }

    void add_edge(int v, int u, long long cap) {
        edges.emplace_back(v, u, cap);
        edges.emplace_back(u, v, 0);
        adj[v].push_back(m);
        adj[u].push_back(m + 1);
        m += 2;
    }

    bool bfs() {
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (int id : adj[v]) {
                if (edges[id].cap - edges[id].flow < 1)
                    continue;
                if (level[edges[id].u] != -1)
                    continue;
                level[edges[id].u] = level[v] + 1;
                q.push(edges[id].u);
            }
        }
        return level[t] != -1;
    }

    long long dfs(int v, long long pushed) {
        if (pushed == 0)
            return 0;
        if (v == t)
            return pushed;
        for (int& cid = ptr[v]; cid < (int)adj[v].size(); cid++) {
            int id = adj[v][cid];
            int u = edges[id].u;
            if (level[v] + 1 != level[u] || edges[id].cap - edges[id].flow < 1)
                continue;
            long long tr = dfs(u, min(pushed, edges[id].cap - edges[id].flow));
            if (tr == 0)
                continue;
            edges[id].flow += tr;
            edges[id ^ 1].flow -= tr;
            return tr;
        }
        return 0;
    }

    long long flow() {
        long long f = 0;
        while (true) {
            fill(level.begin(), level.end(), -1);
            level[s] = 0;
            q.push(s);
            if (!bfs())
                break;
            fill(ptr.begin(), ptr.end(), 0);
            while (long long pushed = dfs(s, flow_inf)) {
                f += pushed;
            }
        }
        return f;
    }
};

bool prime(int x) {
    for (int i=2;i<x;i++) {
        if (x%i==0) return 0;
    }
    return 1;
}

vector<int> adj[1005];
int vis[1005];
vector<vector<int>> ans;

void dfs(int x) {
    vis[x]=1;
    ans.back().pb(x);
    for (auto y: adj[x]) {
        if (!vis[y]) dfs(y);
    }
}

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    int a[n+5];
    for (int i=1;i<=n;i++) cin >> a[i];
    int o=0,e=0;
    for (int i=1;i<=n;i++) {
        if (a[i]%2==0) e++; else o++;
    }
    if (e!=o)  {
        cout << "Impossible" << endl;
        return 0;
    }
    Dinic d(2*n+2,0,2*n+1);
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=n;j++) {
            if (prime(a[i]+a[j])) {
                d.add_edge(i,j+n,1);
            }
        }
    }
    for (int i=1;i<=n;i++) {
        d.add_edge(0,i,2);
        d.add_edge(i+n,2*n+1,2);
    }
    if (d.flow() != 2*n) {
        cout << "Impossible" << endl;
        return 0;
    } 
    for (int i=0;i<d.edges.size();i++) {
        if (d.edges[i].flow == 1) {
            //cout << d.edges[i].v << " " << d.edges[i].u-n << endl;
            adj[d.edges[i].v].pb(d.edges[i].u-n);
            //adj[d.edges[i].u-n].pb(d.edges[i].v);
        }
    }
    memset (vis,0,sizeof(vis));
    for (int i=1;i<=n;i++) {
        if (!vis[i]) {
            ans.pb(vector<int> ());
            dfs(i);
        }
    }
    cout << ans.size() << endl;
    for (int i=0;i<ans.size();i++) {
        cout << ans[i].size() << " ";
        for (int j=0;j<ans[i].size();j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}