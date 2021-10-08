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


vector<LL> adj[50005];
LL par[50005];
LL sz[50005];
bool vis[50005];

LL dfs(LL cur) {
    LL cnt = 1;
    vis[cur] = 1;
    for (auto x : adj[cur]) {
        if (vis[x]) continue;
        cnt += dfs(x);
        par[x] = cur;
    }
    return sz[cur] = cnt;
}

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    LL tc;
    cin >> tc;
    while (tc--) {
        LL n;
        cin >> n;

        for (LL i=1;i<=n;i++) {
            adj[i].clear();
            par[i] = -1;
            sz[i] = -1;
            vis[i] = 0;
        }

        for (LL i=1;i<n;i++) {
            LL x,y;
            cin >> x >> y;
            adj[x].pb(y);
            adj[y].pb(x);
        }

        dfs(1);

        // for (LL i=1;i<=n;i++) cout << par[i] << " ";
        // cout << endl;
        // for (LL i=1;i<=n;i++) cout << sz[i] << " ";
        // cout << endl;
        LL ans = 0;
        for (LL i=2;i<=n;i++) {
            ans += (n-sz[i]) * sz[i];
        }
        cout << ans * 2 << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}