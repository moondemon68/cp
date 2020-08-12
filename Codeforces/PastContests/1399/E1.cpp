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

vector<LL> adj[100005];
LL par[100005];
LL sz[100005];
bool vis[100005];

LL dfs(LL x) {
    LL cnt = 0;
    vis[x] = 1;
    if (adj[x].size() == 1) cnt++;
    for (auto next : adj[x]) {
        if (vis[next]) continue;
        par[next] = x;
        cnt += dfs(next);
    }
    return sz[x] = cnt;
}

struct CustomCompare
{
    bool operator()(const pii& lhs, const pii& rhs)
    {
        return (lhs.fi-lhs.fi/2)*lhs.se < (rhs.fi-rhs.fi/2)*rhs.se;
    }
};

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    LL tc;
    cin >> tc;
    while (tc--) {
        LL n,s;
        cin >> n >> s;
        LL ans = 0;
        map<pii,LL> m;
        for (LL i=1;i<n;i++) {
            LL x,y,w;
            cin >> x >> y >> w;
            m[{x,y}] = w;
            m[{y,x}] = w;
            adj[x].pb(y);
            adj[y].pb(x);
        }
        dfs(1);
        // for (LL i=1;i<=n;i++) {
        //     cout << sz[i] << " ";
        // }
        LL sum = 0;
        priority_queue<pii, vector<pii>, CustomCompare> p;
        for (LL i=2;i<=n;i++) {
            // cout << par[i] << " " << i << " ";
            LL w = m[{par[i], i}];
            sum += w * sz[i];
            // cout << w << " " << sz[i] << endl;
            p.push({w, sz[i]});
        }
        // cout << sum;
        while (sum > s) {
            pii top = p.top();
            p.pop();
            ans++;
            sum -= top.fi * top.se;
            top.fi /= 2;
            if (top.fi == 0) continue;
            sum += top.fi * top.se;
            p.push(top);
        }
        cout << ans << endl;
        for (LL i=1;i<=n;i++) {
            adj[i].clear();
        }
        memset (par,0,sizeof(par));
        memset (vis,0,sizeof(vis));
        memset (sz,0,sizeof(sz));
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
/*
1
8 100
1 3 50
1 5 10
3 2 30
3 6 20
5 7 5
5 4 27
5 8 15
*/