#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
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
    cin >> n >> m;
    int parent[5005];
    memset (parent,0,sizeof(parent));
    int vis[5005];
    for (int i=1;i<=n;i++) vis[i]=MOD;
    vector<pii> adj[5005];
    vector<pii> adj2[5005];
    for (int i=1;i<=m;i++) {
      int u,v,w;
      cin >> u >> v >> w;
      adj[u].pb(mp(w,v));
      adj2[v].pb(mp(w,u));
    }
    priority_queue<pii,vector<pii>,greater<pii> > pq;
    pq.push(mp(0,1));
    vis[1]=0;
    while (!pq.empty()) {
      pii cur=pq.top();
      pq.pop();
      for (int i=0;i<adj[cur.se].size();i++) {
        pii next=adj[cur.se][i];
        if (vis[next.se]>vis[cur.se]+next.fi) {
          vis[next.se]=vis[cur.se]+next.fi;
          parent[next.se]=cur.se;
          pq.push(mp(vis[next.se],next.se));
        }
      }
    }

    int vis2[5005];
    for (int i=1;i<=n;i++) vis2[i]=MOD;
    priority_queue<pii,vector<pii>,greater<pii> > pq2;
    pq2.push(mp(0,n));
    vis2[n]=0;
    while (!pq2.empty()) {
      pii cur=pq2.top();
      pq2.pop();
      for (int i=0;i<adj2[cur.se].size();i++) {
        pii next=adj2[cur.se][i];
        if (vis2[next.se]>vis2[cur.se]+next.fi) {
          vis2[next.se]=vis2[cur.se]+next.fi;
          pq2.push(mp(vis2[next.se],next.se));
        }
      }
    }
    /*
    for (int i=1;i<=n;i++) cout << vis[i] << " ";
    cout << endl;
    for (int i=1;i<=n;i++) cout << vis2[i] << " ";
    cout << endl;
    */
    int ans=MOD;
    for (int i=1;i<=n;i++) {
      for (int j=0;j<adj[i].size();j++) {
        int newdist=vis[i]+vis2[adj[i][j].se]+adj[i][j].fi;
        if (newdist<ans&&newdist>vis[n]) ans=newdist;
      }
    }
    if (ans!=MOD) cout << ans << endl;
    else {
      ans=MOD;
      int mindist=vis[n];
      for (int i=0;i<adj2[n].size();i++) {
        ans=min(ans,mindist+adj2[n][i].fi);
      }
      cout << ans << endl;
      for (int i=1;i<=n;i++) cout << parent[i] << " ";
    }
    return 0;
}
/*
3 2
1 2 2
2 3 4
*/
