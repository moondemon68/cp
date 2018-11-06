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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m;
    cin >> n>> m;
    vector<pii> adj[10005];
    for (int i=1;i<=m;i++) {
      int u,v,w;
      cin >> u >> v >> w;
      adj[u].pb(mp(w,v));
      adj[v].pb(mp(w,u));
    }
    bool MST[10005];
    memset (MST,0,sizeof(MST));
    int vis[10005];
    for (int i=1;i<=n;i++) vis[i]=INT_MAX;
    priority_queue<pii,vector<pii>,greater<pii> > pq;
    pq.push(mp(0,1));
    vis[1]=0;
    while (!pq.empty()) {
      pii cur=pq.top();
      pq.pop();
      MST[cur.se]=1;
      for (int i=0;i<adj[cur.se].size();i++) {
        pii next=adj[cur.se][i];
        if (!MST[next.se]&&vis[next.se]>next.fi) {
          vis[next.se]=next.fi;
          pq.push(next);
        }
      }
    }
    LL ans=0;
    for (int i=1;i<=n;i++) ans+=vis[i];
    cout << ans << endl;
    return 0;
}
