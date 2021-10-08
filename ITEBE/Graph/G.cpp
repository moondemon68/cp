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

vector<int> adj[10005];
int tin[10005], low[10005], vis[10005];
int timer = 0;
set<int> ans;

void dfs(int v, int p) {
    vis[v] = 1;
    tin[v] = timer;
    low[v] = timer;
    timer++;
    int child = 0;
    for (auto next : adj[v]) {
        if (next == p) continue;
        if (vis[next]) {
            low[v] = min(low[v], tin[next]);
        } else {
            dfs(next, v);
            low[v] = min(low[v], low[next]);
            if (low[next] >= tin[v] && p != -1) {
                ans.insert(v);
            }
            child++;
        }
    }
    if (p == -1 && child > 1) ans.insert(v);
}

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m;
    while (cin >> n >> m) {
        if (n == 0) break;
        for (int i=1;i<=m;i++) {
            int x,y;
            cin >> x >> y;
            adj[x].pb(y);
            adj[y].pb(x);
        }
        timer = 0;
        ans.clear();
        memset (vis,0,sizeof(vis));
        memset (tin,-1,sizeof(tin));
        memset (low,-1,sizeof(low));

        dfs(1, -1);
        cout << ans.size() << endl;

        for (int i=1;i<=n;i++) adj[i].clear();
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}