#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define LL long long

using namespace std;

stack<int> ans;
int vis[105];
bool cycle=0;
vector<int> adj[105];

void toposort(int x) {
  vis[x]=1;
  for (int j=0;j<adj[x].size();j++) {
    if (vis[adj[x][j]]==0) {
      vis[adj[x][j]]=1;
      toposort(adj[x][j]);
    } else if (vis[adj[x][j]]==1) cycle=1;
  }
  ans.push(x);
  vis[x]=2;
}

int main () {
    int n,m;
    cin >> n >> m;
    for (int i=1;i<=m;i++) {
      int x,y;
      cin >> x >> y;
      adj[x].pb(y);
    }
    memset (vis,0,sizeof(vis));
    for (int i=1;i<=n;i++) {
      if (!vis[i]) toposort(i);
    }

    if (cycle) cout << "Ada Cycle" << endl;
    else {
      while (!ans.empty()) {
        cout << ans.top() <<" ";
        ans.pop();
      }
    }
    return 0;
}
