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
    int n,m,x;
    cin >> n >> m >> x;
    vector<int> adj[100005];
    int vis[100005];
    memset (vis,0,sizeof(vis));
    for (int i=1;i<=m;i++) {
      int a,b;
      cin >> a >> b;
      adj[b].pb(a);
    }
    queue<int> q;
    q.push(x);
    vis[x]=1;
    while (!q.empty()) {
      int cur=q.front();
      q.pop();
      for (int i=0;i<adj[cur].size();i++) {
        int next=adj[cur][i];
        if (vis[next]==0) {
          vis[next]=vis[cur]+1;
          q.push(next);
        }
      }
    }
    for (int i=1;i<=n;i++) cout << vis[i]-1 << endl;
    return 0;
}
