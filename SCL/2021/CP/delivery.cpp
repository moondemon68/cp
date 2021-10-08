#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<LL,LL>
#define LL long long
using namespace std;

struct Edge {
    LL from, to, capacity, cost;
};

struct Ware {
    LL w, c, p;
};

vector<vector<LL>> adj, cost, capacity;

const LL INF = 1e9;

void shortest_paths(LL n, LL v0, vector<LL>& d, vector<LL>& p) {
    d.assign(n, INF);
    d[v0] = 0;
    vector<bool> inq(n, false);
    queue<LL> q;
    q.push(v0);
    p.assign(n, -1);

    while (!q.empty()) {
        LL u = q.front();
        q.pop();
        inq[u] = false;
        for (LL v : adj[u]) {
            if (capacity[u][v] > 0 && d[v] > d[u] + cost[u][v]) {
                d[v] = d[u] + cost[u][v];
                p[v] = u;
                if (!inq[v]) {
                    inq[v] = true;
                    q.push(v);
                }
            }
        }
    }
}

LL min_cost_flow(LL N, vector<Edge> edges, LL K, LL s, LL t) {
    adj.assign(N, vector<LL>());
    cost.assign(N, vector<LL>(N, 0));
    capacity.assign(N, vector<LL>(N, 0));
    for (Edge e : edges) {
        adj[e.from].push_back(e.to);
        adj[e.to].push_back(e.from);
        cost[e.from][e.to] = e.cost;
        cost[e.to][e.from] = -e.cost;
        capacity[e.from][e.to] = e.capacity;
    }

    LL flow = 0;
    LL cost = 0;
    vector<LL> d, p;
    while (flow < K) {
        shortest_paths(N, s, d, p);
        if (d[t] == INF)
            break;

        // find max flow on that path
        LL f = K - flow;
        LL cur = t;
        while (cur != s) {
            f = min(f, capacity[p[cur]][cur]);
            cur = p[cur];
        }

        // apply flow
        flow += f;
        cost += f * d[t];
        cur = t;
        while (cur != s) {
            capacity[p[cur]][cur] -= f;
            capacity[cur][p[cur]] += f;
            cur = p[cur];
        }
        cout << cost << endl;
    }

    if (flow < K)
        return -1;
    else
        return cost;
}

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    LL n, d, e;
    cin >> n >> d >> e;
    LL a[n+5][n+5];
    memset(a,0,sizeof(a));
    for (LL i=0;i<n;i++) {
        for (LL j=0;j<n;j++) {
            a[i][j] = INF;
            if (i == j) a[i][j] = 0;
        }
    }
    for (LL i=1;i<=e;i++) {
        LL u,v;
        cin >> u >> v;
        u--; v--;
        a[u][v] = 1;
        a[v][u] = 1;
    }
    for (LL k = 0; k < n; ++k) {
        for (LL i = 0; i < n; ++i) {
            for (LL j = 0; j < n; ++j) {
                a[i][j] = min(a[i][j], a[i][k] + a[k][j]); 
            }
        }
    }
    // for (LL i=0;i<n;i++) {
    //     for (LL j=0;j<n;j++) cout << a[i][j] << " ";
    //     cout << endl;
    // }
    vector<Ware> ware;
    for (LL i=1;i<=d;i++) {
        LL w,c,p;
        cin >> w >> c >> p;
        p--;
        ware.pb({w, c, p});
    }

    vector<pii> order;
    LL m;
    cin >> m;
    LL cnt[n+5];
    memset(cnt,0,sizeof(cnt));
    for (LL i=1;i<=m;i++) {
        LL k, g;
        cin >> k >> g;
        g--;
        cnt[g] += k;
        // order.pb({k, g});
    }
    for (LL i=0;i<n;i++) {
        if (cnt[i] != 0) order.pb({cnt[i], i});
    }

    vector<Edge> edges; // from, to, capacity, cost;
    for (LL i=0;i<d;i++) {
        for (LL j=0;j<order.size();j++) {
            edges.pb({ware[i].p, order[j].se + n, INF, a[ware[i].p][order[j].se] * ware[i].w});
        }
    }
    for (LL i=0;i<d;i++) {
        edges.pb({n * 2, ware[i].p, ware[i].w, 0});
    }
    for (LL i=0;i<order.size();i++) {
        edges.pb({order[i].se + n, n * 2 + 1, order[i].fi, 0});
    }

    // n source, n + 1 sink
    cout << min_cost_flow(n * 2 + 2, edges, INF, n * 2, n * 2 + 1) << endl;

    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}