#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define ll long long
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define pii pair<LL, LL>
#define pll pair<LL, LL>

const LL N = 3e5 + 5;
const LL INF = 1e18;
vector<vector<pair<LL, LL>>> adj;

void dijkstra(LL s, LL e, vector<LL> &d, vector<LL> &p, LL cannot = -1)
{
    LL n = adj.size();
    d.assign(n, INF);
    p.assign(n, -1);

    d[s] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> q;
    q.push({0, s});
    while (!q.empty())
    {
        LL v = q.top().second;
        LL d_v = q.top().first;
        q.pop();
        // if (d[e] != INF) {
        //     break;
        // }
        if (d_v != d[v])
            continue;

        for (auto edge : adj[v])
        {
            LL to = edge.first;
            LL len = edge.second;

            if (d[v] + len < d[to] && cannot != to)
            {
                d[to] = d[v] + len;
                p[to] = v;
                q.push({d[to], to});
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    LL n, m, s, t;
    cin >> n >> m >> s >> t;
    adj.resize(n + 1);
    for (LL i = 0; i < m; i++)
    {
        LL a, b;
        LL d;
        cin >> a >> b >> d;
        adj[a].pb({b, d});
        adj[b].pb({a, d});
    }
    if (n < 1000)
    {

        vector<LL> d(n + 1);
        vector<LL> p(n + 1);
        dijkstra(s, t, d, p);

        vector<LL> path;
        map<pii, LL> dist;
        LL cur = t;
        while (cur != s)
        {
            dist[{p[cur], cur}] = d[cur] - d[p[cur]];
            path.pb(cur);
            cur = p[cur];
        }
        path.pb(s);

        reverse(path.begin(), path.end());
        // cout << endl;
        LL pre[path.size()], suf[path.size()];
        pre[0] = 0;
        for (LL i = 1; i < path.size(); i++)
        {
            pre[i] = pre[i - 1] + dist[{p[path[i]], path[i]}];
        }

        suf[path.size() - 1] = 0;
        for (LL i = path.size() - 2; i >= 0; i--)
        {
            suf[i] = suf[i + 1] + dist[{p[path[i + 1]], path[i + 1]}];
        }
        // for (LL i=0;i<path.size();i++) {
        //     cout << pre[i] << " " << suf[i] << " " << path[i] << endl;
        // }
        // cout << endl;

        LL maxans = 0, maxi = -1;
        for (LL i = 1; i < path.size() - 1; i++)
        {
            LL ans = 0;
            ans = pre[i - 1] + suf[i + 1];
            dijkstra(path[i - 1], path[i + 1], d, p, path[i]);
            if (d[path[i + 1]] != INF)
            {
                ans += d[path[i + 1]];
                if (ans > maxans)
                {
                    maxans = ans;
                    maxi = path[i];
                }
            }
            else
            {
                ans = INF;
            }
            cout << path[i-1] << " " << path[i] << " " << path[i+1] << " " << ans << endl;
        }

        cout << maxi << endl;
    }
    else
    {
        pll ans = {-1e9, -1}; // distance, node

        for (int removedNode = 1; removedNode <= n; removedNode++)
        {
            vector<ll> d(n + 1, INF);
            priority_queue<pll, vector<pll>, greater<pll>> pq;
            vector<bool> vis(n + 1, false);
            d[s] = 0;
            pq.push({0, s});
            while (!pq.empty())
            {
                auto it = pq.top();
                int v = it.second;
                pq.pop();

                if (v == removedNode)
                { // no need i think
                    continue;
                }
                if (vis[v])
                {
                    continue;
                }
                vis[v] = 1;

                for (auto x : adj[v])
                {
                    if (x.first != removedNode && d[v] + x.second < d[x.first])
                    {
                        d[x.first] = d[v] + x.second;
                        pq.push({d[x.first], x.first});
                    }
                }
            }
            if (d[t] == INF)
            {
                continue;
            }
            ans = max(ans, {d[t], d[t] == INF ? -1 : removedNode});
        }
        cout << ans.se << '\n';
    }
    return 0;
}