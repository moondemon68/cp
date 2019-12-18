#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define LL long long
using namespace std;

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m;
    cin >>n >> m;
    int v[n+5];
    memset (v,0,sizeof(v));
    int t[n+5];
    vector<int> adj[n+5];
    vector<pii> edge;
    for (int i=1;i<=m;i++) {
        int x,y;
        cin >> x >> y;
        if (x>y) swap(x,y);
        edge.pb(mp(x,y));
        adj[x].pb(y);
        adj[y].pb(x);
    }
    bool vis[n+5];
    memset (vis,0,sizeof(vis));
    vis[1]=1;
    v[1]=1;
    for (int i=0;i<adj[1].size();i++) {
        int next = adj[1][i];
        if (!vis[next]) {
            vis[next]=1;
        }
    }
    int p=-1;
    for (int i=1;i<=n;i++) {
        if (v[i]==0 && !vis[i]) v[i]=1;
    }
    for (int i=1;i<=n;i++) {
        if (v[i]==0) p=i;
    }
    if (p == -1) {
        cout << "-1" << endl;
        return 0;
    }

    memset (vis,0,sizeof(vis));
    vis[p]=1;
    v[p]=2;
    for (int i=0;i<adj[p].size();i++) {
        int next = adj[p][i];
        if (!vis[next]) {
            vis[next]=1;
        }
    }
    p=-1;
    for (int i=1;i<=n;i++) {
        if (v[i]==0 && !vis[i]) v[i]=2; 
    }
    for (int i=1;i<=n;i++) {
        if (v[i]==0) p=i;
    }
    if (p == -1) {
        cout << "-1" << endl;
        return 0;
    }

    memset (vis,0,sizeof(vis));
    vis[p]=1;
    v[p]=3;
    for (int i=0;i<adj[p].size();i++) {
        int next = adj[p][i];
        if (!vis[next]) {
            vis[next]=1;
        }
    }
    for (int i=1;i<=n;i++) {
        if (v[i]==0 && !vis[i]) v[i]=3;
    }

    vector<int> v1,v2,v3;
    for (int i=1;i<=n;i++) {
        if (v[i]==0) {
            cout << -1 << endl;
            return 0;
        } 
        else if (v[i]==1) v1.pb(i);
        else if (v[i]==2) v2.pb(i);
        else if (v[i]==3) v3.pb(i);
    }
    if (m != v1.size()*v2.size()+v2.size()*v3.size()+v1.size()*v3.size()) {
        cout << -1 << endl;
        return 0;
    }
    for (int i=0;i<edge.size();i++) {
        int x=v[edge[i].fi], y=v[edge[i].se];
        if (x == y) {
            cout << -1 << endl;
            return 0;
        }
    }

    for (int i=1;i<=n;i++) cout << v[i] << " ";
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}