#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define LL long long
using namespace std;

bool cmp(pair<pii, int> a, pair<pii, int> b) {
    return a.se > b.se;
}

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector<pii> vvv;
    vector<int> adj[n+5];
    int f[n+5][n+5];
    memset (f,0,sizeof(f));
    for (int i=1;i<n;i++) {
        int x,y;
        cin >> x >> y;
        vvv.pb({x, y});
        adj[x].pb(y);
        adj[y].pb(x);
    }
    int m;
    cin >> m;
    pair<pii, int> p[m+5];
    for (int i=1;i<=m;i++) cin >> p[i].fi.fi >> p[i].fi.se >> p[i].se;
    sort (p+1, p+m+1, cmp);
    int vis[n+5];
    int par[n+5];
    for (int i=1;i<=m;i++) {
        memset (vis,-1,sizeof(vis));
        memset (par,-1,sizeof(par));
        queue<int> q;
        int start = p[i].fi.fi, end = p[i].fi.se;
        q.push(start);
        vis[start] = 0; 
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            for (int i=0;i<adj[cur].size();i++) {
                int next = adj[cur][i];
                if (vis[next] == -1) {
                    par[next] = cur;
                    vis[next] = vis[cur] + 1;
                    q.push(next);
                }
            }
            if (vis[end] != -1) break;
        }
        int cur = end;
        bool y = 0;
        while (cur != start) {
            if (f[cur][par[cur]] <= p[i].se) y = 1;
            if (f[par[cur]][cur] <= p[i].se) y = 1;
            f[cur][par[cur]] = max(f[cur][par[cur]], p[i].se);
            f[par[cur]][cur] = max(f[par[cur]][cur], p[i].se);
            cur = par[cur];
        }
        if (!y) {
            cout << -1 << endl;
            return 0;
        }
    }
    for (int i=0;i<vvv.size();i++) {
        if (f[vvv[i].fi][vvv[i].se] == 0) cout << 1 << " ";
        else cout << f[vvv[i].fi][vvv[i].se] << " ";
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}