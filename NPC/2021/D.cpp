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

const LL MAXN = 100000;
vector<pii> adj[MAXN+5];
vector<LL> par[MAXN+5];
LL dist[MAXN+5];

void find(vector<vector<LL>>& paths, vector<LL>& path, LL cur) {
    if (cur == -1) {
        paths.pb(path);
        return;
    }
    for (LL p : par[cur]) {
        path.pb(cur);
        find(paths, path, p);
        path.pop_back();
    }
}

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    LL n, m, a, b;
    cin >> n >> m >> a >> b;
    for (LL i=1;i<=m;i++) {
        LL u, v, w;
        cin >> u >> v >> w;
        adj[u].pb({v, w});
        adj[v].pb({u, w});
    }

    for (LL i=1;i<=n;i++) {
        dist[i] = INT_MAX;
    }

    priority_queue<pii, vector<pii>, greater<pii>> q;
    q.push({0, a});
    par[a] = { -1 };
    dist[a] = 0;
    while (!q.empty()) {
        pii cur = q.top();
        q.pop();
        for (pii next : adj[cur.se]) {
            if (dist[next.fi] > dist[cur.se] + next.se) {
                dist[next.fi] = dist[cur.se] + next.se;
                q.push({dist[next.fi], next.fi});
                par[next.fi].clear();
                par[next.fi].pb(cur.se);
            } else if (dist[next.fi] == dist[cur.se] + next.se) {
                par[next.fi].pb(cur.se);
            }
        }
        // if (dist[b] != INT_MAX) break;
    }

    vector<vector<LL>> paths;
    vector<LL> path;
    find(paths, path, b);

    int cnt[n+5];
    memset(cnt,0,sizeof(cnt));

    for (auto v : paths) {
        for (LL u : v) {
            // cout << u << " ";
            cnt[u]++;
        }
        // cout << endl;
    }
    for (int i=1;i<=n;i++) {
        cout << fixed << setprecision(12) << (float)cnt[i] / (float)paths.size() * 2 << endl;
    }

    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}