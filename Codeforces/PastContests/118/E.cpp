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

int n,m;
vector<int> adj[100005];
int vis[100005];
vector<pii> backedge, spanedge;
int dp[100005];
bool bridge = 0;

int dfs(int u, int par) {
    vis[u] = 1;
    int cnt = 0;
    for (auto v : adj[u]) {
        if (v == par) continue;
        if (vis[v] == 0) {
            spanedge.pb(mp(u, v));
            cnt += dfs(v, u);
        } else if (vis[v] == 1) {
            dp[v]++;
            cnt++;
            backedge.pb(mp(u, v));
        }
    }
    cnt -= dp[u];
    if (cnt == 0 && u != 1) {
        bridge = 1;
    }
    vis[u] = 2;
    return cnt;
}

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for (int i=1;i<=m;i++) {
        int x,y;
        cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    memset(vis,0,sizeof(vis));
    memset(dp,0,sizeof(dp));
    dfs(1, 0);
    // for (int i=1;i<=n;i++) {
    //     cout << i << " -> ";
    //     for (int j=0;j<adj[i].size();j++) {
    //         cout << adj[i][j] << "," << ans[mp(i,adj[i][j])] << " ";
    //     }
    //     cout << endl;
    // }
    if (bridge == 1) {
        cout << 0 << endl;
        return 0;
    }
    for (int i=0;i<spanedge.size();i++) cout << spanedge[i].fi << " " << spanedge[i].se << endl;
    for (int i=0;i<backedge.size();i++) cout << backedge[i].fi << " " << backedge[i].se << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}