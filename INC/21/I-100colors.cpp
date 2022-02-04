#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<LL,LL>
#define LL long long
using namespace std;

const LL INF = 1e18;

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    LL n, m;
    cin >> n >> m;
    vector<pair<LL, pair<LL, LL>>> adj[n+5];
    for (LL i=1;i<=m;i++) {
        LL u, v, w;
        LL c;
        cin >> u >> v >> c >> w;
        u--;
        v--;
        adj[u].pb({v, {w, c}});
        adj[v].pb({u, {w, c}});
    }
    vector<LL> d((n + 2) * 99, INF);
    priority_queue<pair<pii, LL>, vector<pair<pii, LL>>, greater<pair<pii, LL>>> pq;
    d[1] = 0;
    pq.push({{0, 0}, 1});
    while (!pq.empty()) {
        auto it = pq.top();
        cout << it.fi.fi << " " << it.fi.se << " " << it.se << endl;
        LL v = it.fi.se;
        pq.pop();
        if (d[v * 99 + it.se] != it.fi.fi) continue;
        for (auto next : adj[v]) {
            LL dist = next.se.fi;
            if (next.se.se != it.se) {
                dist += abs(next.se.se - it.se);
            }
            if (d[v * 99 + it.se] + dist < d[next.fi*99 + next.se.se]) {
                d[next.fi*99 + next.se.se] = d[v * 99 + it.se] + dist;
                pq.push({{d[next.fi*99 + next.se.se], next.fi}, next.se.se});
            }
        }
    }
    LL ans = INT_MAX;
    for (int i=1;i<99;i++) {
        ans = min(ans, d[(n-1)*99+i] + i-1);
    }
    cout << ans << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
/*
1
5 6 60
1 2 20 b
1 3 40 b
2 3 10 a
2 4 10 a
5 4 10 a
5 3 20 a
*/