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
int tin[200005], tout[200005], vis[200005], p[200005];
int x = 0;

void dfs(int cur, int par) {
    tin[cur] = x++;
    for (int i=0;i<adj[cur].size();i++) {
        int next = adj[cur][i];
        if (next != par) {
            vis[next] = vis[cur] + 1;
            p[next] = cur;
            dfs(next, cur);
        }
    }
    tout[cur] = x++;
}

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,q;
    cin >> n >> q;
    for (int i=1;i<n;i++) {
        int x,y;
        cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    memset (vis,-1,sizeof(vis));
    memset (p,0,sizeof(p));
    vis[1] = 0;
    dfs(1,0);
    // for (int i=1;i<=n;i++) cout << vis[i] << "\t";
    // cout << endl;
    // for (int i=1;i<=n;i++) cout << tin[i] << "\t";
    // cout << endl;
    // for (int i=1;i<=n;i++) cout << tout[i] << "\t";
    // cout << endl;
    
    while (q--) {
        int k;
        cin >> k;
        int a[k+5];
        for (int i=1;i<=k;i++) cin >> a[i];
        int d = 1;
        for (int i=2;i<=k;i++) {
            if (vis[a[i]] > vis[a[d]]) d = i;
        }
        for (int i=1;i<=k;i++) {
            if (i == d) continue;
            if (a[i] != 1) a[i] = p[a[i]];
        }
        bool y = 1;
        for (int i=1;i<=k;i++) {
            if (i == d) continue;
            if (!(tin[a[i]] < tin[a[d]] && tout[a[d]] < tout[a[i]])) y = 0;
        }
        if (y) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}