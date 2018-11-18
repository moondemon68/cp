#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define LL long long

using namespace std;
LL a[100005];
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for (int i=1;i<=n;i++) cin >> a[i];
    LL ans=0;
    vector<int> adj[100005];
    for (int i=1;i<n;i++) {
      int x,y;
      cin >> x >> y;
      adj[x].pb(y);
      adj[y].pb(x);
    }
    for (int i=1;i<=n;i++) {
      LL vis[100005];
      memset (vis,-1,sizeof(vis));
      stack<LL> s;
      s.push(i);
      vis[i]=a[i];
      while (!s.empty()) {
        int cur=s.top();
        s.pop();
        for (int j=0;j<adj[cur].size();j++) {
          int next=adj[cur][j];
          if (vis[next]==-1) {
            vis[next]=vis[cur]^a[next];
            s.push(next);
          }
        }
      }
      for (int j=i;j<=n;j++) {
          //cout << i << " " << j << " " << max(vis[j],(LL)0) << endl;
          ans+=max(vis[j],(LL)0);
      }
    }
    cout << ans << endl;
    return 0;
}
