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

map<pii, LL> cost;

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    LL n,q;
    cin >> n >> q;
    LL a[n+5];
    for (LL i=1;i<=n;i++) cin >> a[i];
    vector<pii> adj[n+5];
    for (LL i=1;i<n;i++) {
        LL x,y,w;
        cin >> x >> y >> w;
        adj[x].pb({y, w});
        adj[y].pb({x, w});
        cost[{x, y}] = w;
        cost[{y, x}] = w;
    }
    while (q--) {
        LL x,y;
        cin >> x >> y;
        LL vis[n+5], par[n+5];
        for (LL i=1;i<=n;i++) vis[i] = 1e18;
        stack<LL> s;
        vis[x] = a[x];
        s.push(x);
        while (!s.empty()) {
            LL cur = s.top();
            s.pop();
            for (auto next : adj[cur]) {
                if (vis[next.fi] == 1e18) {
                    vis[next.fi] = vis[cur] - next.se;
                    vis[next.fi] += a[next.fi];
                    par[next.fi] = cur;
                    s.push(next.fi);
                }
            }
            if (vis[y] != 1e18) break;
        }
        // for (LL i=1;i<=n;i++) cout << vis[i] << " ";
        LL mini = 1e18, cur = y;
        while (cur != x) {
            mini = min(mini, vis[par[cur]] - cost[{cur, par[cur]}]);
            cur = par[cur];
        }
        cout << max(0LL, -1 * mini) << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}