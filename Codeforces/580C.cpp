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
    int a[100005];
    for (int i=1;i<=n;i++) cin >> a[i];
    vector<int> adj[100005];
    for (int i=1;i<n;i++) {
      int x,y;
      cin >> x >> y;
      adj[x].pb(y);
      adj[y].pb(x);
    }
    int vis[100005];
    memset (vis,-1,sizeof(vis));
    stack<int> s;
    s.push(1);
    vis[1]=a[1];
    int ans=0;
    while (!s.empty()) {
      int cur=s.top();
      s.pop();
      for (int i=0;i<adj[cur].size();i++) {
        int next=adj[cur][i];
        if (vis[next]!=-1||vis[next]==1000000) continue;
        if (a[next]==1) {
          vis[next]=vis[cur]+1;
          if (vis[next]>m) {
            vis[next]=1000000;
            stack<int> t;
            t.push(next);
            while (!t.empty()) {
              int curr=t.top();
              t.pop();
              for (int j=0;j<adj[curr].size();j++) {
                int nextt=adj[curr][j];
                if (vis[nextt]==-1) {
                  vis[nextt]=vis[next];
                  t.push(nextt);
                }
              }
            }
          }
        } else vis[next]=0;
        s.push(next);
      }
      if (adj[cur].size()==1&&cur!=1) {
          if (vis[cur]<=m) ans++;
      }
    }
    //for (int i=1;i<=n;i++) cout << vis[i] << " ";
    cout << ans << endl;
    return 0;
}
