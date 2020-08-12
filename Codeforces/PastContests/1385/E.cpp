#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define INF 1234567890
#define pii pair<int,int>
#define LL long long
using namespace std;

vector<int> adj[200005];
int vis[200005];
vector<int> sorted;
int p[200005];
int par[200005];
bool bad = 0;

void dfs(int u, int pu) {
    if (vis[u] == 2) return;
    if (vis[u] == 1) {
        bad = 1;
        return;
    }
    par[u] = pu;
    vis[u] = 1;
    for (auto v : adj[u]) {
        if (v == pu) continue;
        dfs(v, u);
    }
    vis[u] = 2;
    sorted.pb(u);
}

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc;
    cin >> tc;
    while (tc--) {
        int n,m;
        cin >> n >> m;
        vector<pii> e;
        vector<pii> ans;
        for (int i=1;i<=m;i++) {
            int t,x,y;
            cin >> t >> x >> y;
            if (t == 1) {
                ans.pb({x,y});
                adj[x].pb(y);
            } else {
                e.pb({x,y});
            }
        }
        for (int i=1;i<=n;i++) {
            if (vis[i] == 0) {
                dfs(i, 0);
            }
        }
        for (int i=0;i<sorted.size();i++) {
            p[sorted[i]] = i;
        }

        for (auto x : e) {
            if (p[x.fi] >= p[x.se]) ans.pb(x);
            else ans.pb({x.se, x.fi});
        }
        if (bad) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
            for (auto x : ans) {
                cout << x.fi << " " << x.se << endl;
            }
        }

        memset (par,0,sizeof(par));
        memset (vis,0,sizeof(vis));
        for (int i=1;i<=n;i++) {
            adj[i].clear();
        }
        sorted.clear();
        bad = 0;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}