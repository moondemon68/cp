#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<LL, LL>
#define LL long long
using namespace std;
using namespace __gnu_pbds;

#pragma GCC target("avx2")
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")

const LL INF = 1e18;
const int N = 2e5 + 5;
struct HASH
{
    size_t operator()(const pii &x) const
    {
        return hash<LL>()(((LL)x.first) ^ (((LL)x.second) << 32));
    }
};
gp_hash_table<pii, LL, HASH> d;
// unordered_map<pii, LL, HASH> d;
vector<pair<int, pair<LL, LL>>> adj[N];

int main()
{
    // clock_t start = clock();

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    for (LL i = 1; i <= m; i++)
    {
        LL u, v, w;
        LL c;
        cin >> u >> v >> c >> w;
        u--;
        v--;
        adj[u].pb({v, {w, c}});
        adj[v].pb({u, {w, c}});
    }
    priority_queue<pair<pii, LL>, vector<pair<pii, LL>>, greater<pair<pii, LL>>>
        pq;
    d[{0, 1}] = 0;
    pq.push({{0, 0}, 1});
    while (!pq.empty())
    {
        auto it = pq.top();
        LL v = it.fi.se;
        pq.pop();
        LL dvitse;
        if (d[{v, it.se}] == 0)
        {
            d[{v, it.se}] = INF;
            continue;
        }
        else
        {
            dvitse = d[{v, it.se}];
        }

        if (dvitse != it.fi.fi)
            continue;
        for (const auto &next : adj[v])
        {
            LL dist = next.se.fi;
            dist += abs(next.se.se - it.se);
            LL dnextfise;
            if (d[{next.fi, next.se.se}] == 0)
            {
                d[{next.fi, next.se.se}] = INF;
                dnextfise = INF;
            }
            else
            {
                dnextfise = d[{next.fi, next.se.se}];
            }
            if (dvitse + dist < dnextfise)
            {
                dnextfise = dvitse + dist;
                d[{next.fi, next.se.se}] = dnextfise;
                pq.push({{dnextfise, next.fi}, next.se.se});
            }
        }
    }

    LL ans = INF;
    for (const auto &x : d)
    {
        int node = x.fi.fi;
        LL color = x.fi.se;
        cout << node << " " << color << " " << x.se << endl;
        if (node == n - 1)
        {
            ans = min(ans, x.se + color - 1);
        }
    }
    cout << ans << endl;
    // cerr << fixed << setprecision(3) << (clock() - start) * 1. /
    // CLOCKS_PER_SEC
    //      << endl;
    return 0;
}