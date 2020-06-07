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

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m;
    cin >> n >> m;
    vector<int> adj[n+5];
    for (int i=1;i<=m;i++) {
        int x, y;
        cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    vector<pii> v;
    int c[n+5];
    for (int i=1;i<=n;i++) {
        int x;
        cin >> x;
        c[i] = x;
        v.pb({x, i});
    }
    sort (v.begin(), v.end());
    bool vis[n+5];
    memset (vis,0,sizeof(vis));
    vector<int> ans;
    for (int i=0;i<v.size();i++) {
        int cnt = 0;
        int x = v[i].fi;
        int cur = v[i].se;
        for (int j=0;j<adj[cur].size();j++) {
            int next = adj[cur][j];
            if (!vis[c[next]] && c[next] <= x) {
                vis[c[next]] = 1;
                cnt++;
            }
            if (c[next] == c[cur]) {
                cout << -1 << endl;
                return 0;
            }
        }
        if (cnt != c[cur]-1) {
            cout << -1 << endl;
            return 0;
        }
        ans.pb(cur);
        for (int j=0;j<adj[cur].size();j++) {
            int next = adj[cur][j];
            vis[c[next]] = 0;
        }
    }
    for (int i=0;i<ans.size();i++) cout << ans[i] << " ";
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}