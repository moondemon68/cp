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
    int tc;
    cin >> tc;
    while (tc--) {
      int n,m;
      cin >> n >> m;
      vector<pii> adj[10005];
      for (int i=1;i<=m;i++) {
        int x,y,w;
        cin >> x >> y >> w;
        adj[x].pb(mp(w,y));
      }
      int s,e;
      cin >> s >> e;
      priority_queue<pii,vector<pii>,greater<pii> > d;
      int vis[10005];
      for (int i=1;i<=n;i++) vis[i]=INT_MAX;
      vis[s]=0;
      d.push(mp(0,s));
      while (!d.empty()) {
        pii cur=d.top();
        d.pop();
        for (int i=0;i<adj[cur.se].size();i++) {
          pii next=adj[cur.se][i];
          if (vis[cur.se]+next.fi<vis[next.se]) {
            vis[next.se]=vis[cur.se]+next.fi;
            d.push(mp(vis[next.se],next.se));
          }
        }
      }
      if (vis[e]==INT_MAX) cout << "NO" << endl; else cout << vis[e] << endl;
    }
    return 0;
}
