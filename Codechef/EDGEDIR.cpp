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
      vector<int> adj[n+5];
      int vis[n+5];
      memset (vis,0,sizeof(vis));
      vector<pii> edge;
      for (int i=1;i<=m;i++) {
        int x,y;
        cin >> x >> y;
        edge.pb(mp(x,y));
        adj[x].pb(y);
        adj[y].pb(x);
      }
      queue<int> s;
      s.push(1);
      vis[1]=1;
      while (!s.empty()) {
        int cur=s.front();
        s.pop();
        for (int i=0;i<adj[cur].size();i++) {
          int next=adj[cur][i];
          if (vis[next]==0) {
            vis[next]=vis[cur]+1;
            s.push(next);
          }
        }
      }
      priority_queue<pii> p;
      for (int i=1;i<=n;i++) p.push(mp(vis[i],i));
      int indeg[n+5];
      memset (indeg,0,sizeof(indeg));
      int first=1;
      bool done[n+5];
      memset (done,0,sizeof(done));
      vector<pii> ans;
      while (!p.empty()) {
        int cur=p.top().se;
        p.pop();
        done[cur]=1;
        if (first) {
          for (int i=0;i<adj[cur].size();i++) {
            int next=adj[cur][i];
            if (!done[next]) {
              indeg[next]++;
              ans.pb(mp(cur,next));
            }
          }
          first=0;
        } else {
          int size=adj[cur].size();
          if ((size+indeg[cur])%2==0) {
            for (int i=0;i<size;i++) {
              int next=adj[cur][i];
              if (done[next]) continue;
              indeg[cur]++;
              ans.pb(mp(next,cur));
            }
          } else {
            for (int i=0;i<=0;i++) {
              int next=adj[cur][i];
              if (done[next]) continue;
              indeg[cur]++;
              ans.pb(mp(next,cur));
            }
            for (int i=1;i<size;i++) {
              int next=adj[cur][i];
              if (done[next]) continue;
              indeg[next]++;
              ans.pb(mp(cur,next));
            }
          }
        }
      }
      bool y=1;
      for (int i=1;i<=n;i++) {
        if (indeg[i]%2==1) {
          y=0;
          break;
        }
      }
      //for (int i=0;i<m;i++) cout << ans[i].fi << ans[i].se << endl;
      if (!y) cout << -1 << endl;
      else {
        int answer[m+5];
        memset (answer,-1,sizeof(answer));
        for (int i=0;i<ans.size();i++) {
          for (int j=0;j<edge.size();j++) {
            if (ans[i].fi==edge[j].fi&&ans[i].se==edge[j].se) {
              answer[j]=0;
              break;
            }
            if (ans[i].se==edge[j].fi&&ans[i].fi==edge[j].se) {
              answer[j]=1;
              break;
            }
          }
        }
        for (int i=0;i<m;i++) cout << answer[i] << " ";
        cout << endl;
      }
    }
    return 0;
}
