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
    cin >> n >> m;
    vector<pii> adj[100005];
    for (int i=1;i<=m;i++) {
      int a,b,c;
      cin >> a >> b >> c;
      adj[a].pb(mp(c,b));
      adj[b].pb(mp(c,a));
    }
    bool vis[100005];
    memset (vis,0,sizeof(vis));
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    int ans=0;
    pq.push(mp(0,1));
    while (!pq.empty()) {
      pii cur=pq.top();
      pq.pop();
      if (vis[cur.se]) continue;
      ans+=cur.fi;
      vis[cur.se]=1;
      for (int i=0;i<adj[cur.se].size();i++) {
        int next=adj[cur.se][i].se;
        if (!vis[next]) pq.push(adj[cur.se][i]);
      }
    }
    cout << ans << endl;
    return 0;
}
