#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define LL long long

using namespace std;

pii edge[1000005];
int indeg[1000005];
queue<int> ans;
vector<int> adj[1000005];
vector<int> realans[1000005];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m;
    cin >> n >> m;
    for (int i=1;i<=m;i++) {
      cin >> edge[i].fi >> edge[i].se;
      adj[edge[i].fi].pb(edge[i].se);
    }
    memset (indeg,0,sizeof(indeg));
    for (int i=1;i<=m;i++) {
      indeg[edge[i].se]++;
    }
    queue<int> q;
    for (int i=1;i<=n;i++) {
      if (indeg[i]==0) q.push(i);
    }
    while (!q.empty()) {
      int size=q.size();
      queue<int> cetak;
      int cur1=q.front();
      q.pop();
      cetak.push(cur1);
      for (int i=0;i<adj[cur1].size();i++) {
        int next1=adj[cur1][i];
        indeg[next1]--;
        if (indeg[next1]==0) q.push(next1);
      }

      if (size>1) {
        int cur2=q.front();
        q.pop();
        cetak.push(cur2);
        for (int i=0;i<adj[cur2].size();i++) {
          int next2=adj[cur2][i];
          indeg[next2]--;
          if (indeg[next2]==0) q.push(next2);
        }
      }

      ans.push(cetak.size());
      while (!cetak.empty()) {
        ans.push(cetak.front());
        cetak.pop();
      }
      ans.push(-1);
    }

    int cnt=0;
    while (!ans.empty()) {
      if (ans.front()==-1) cnt++; else realans[cnt].pb(ans.front());
      ans.pop();
    }
    cout << cnt << endl;
    for (int i=cnt-1;i>=0;i--) {
      for (int j=0;j<realans[i].size();j++) {
        cout << realans[i][j] << " ";
      }
      cout << endl;
    }
    return 0;
}
//KAHN's ALGORITHM - TOPOSORT
