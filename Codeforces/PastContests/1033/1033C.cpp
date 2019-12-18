#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define LL long long

using namespace std;

int p[100005];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    int a[100005];
    for (int i=1;i<=n;i++) cin >> a[i];
    vector<int> adj[100005];
    for (int i=1;i<=n;i++) {
      for (int j=i;j<=n;j+=a[i]) adj[i].pb(a[j]);
      for (int j=i-a[i];j>=1;j-=a[i]) adj[i].pb(a[j]);
    }
    int moves[100005];
    for (int i=1;i<=n;i++) {
      queue<int> q;
      memset (moves,0,sizeof(moves));
      q.push(i);
      moves[i]=0;
      int ans=0;
      while (!q.empty()) {
        int cur=q.front();
        q.pop();
        for (int j=0;j<adj[cur].size();j++) {
          int next=adj[cur][j];
          if (moves[next]==0) {
            moves[next]=moves[cur]+1;
            ans=max(ans,moves[next]);
            q.push(next);
          }
        }
      }
      p[i]=ans%2;
    }
    for (int i=1;i<=n;i++) {
      if (p[a[i]]==1) cout << "A"; else cout << "B";
    }
    return 0;
}
