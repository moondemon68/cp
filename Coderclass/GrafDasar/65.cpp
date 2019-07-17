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
    int n,m,k;
    cin >> n >> m >> k;
    vector<int> adj[n+5];
    for (int i=1;i<=m;i++) {
        int x,y;
        cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    int vis[k+5][n+5];
    memset (vis,-1,sizeof(vis));
    pii f[k+5];
    for (int i=1;i<=k;i++) {
        cin >> f[i].fi;
        f[i].se=i;
    }
    sort (f+1,f+k+1);
    for (int i=1;i<=k;i++) {
        vis[f[i].se][f[i].fi]=0;
        queue<int> q;
        q.push(f[i].fi);
        while (!q.empty()) {
            
        }
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}