#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define LL long long

using namespace std;

vector<int> adj[1000005];
int cnt[1000005];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m;
    cin >> n >> m;
    for (int i=1;i<=m;i++) {
      int x,y;
      cin >> x >> y;
      adj[y].pb(x);
    }
    memset (cnt,0,sizeof(cnt));
    for (int i=1;i<=n;i++) {
      for (int j=0;j<adj[i].size();j++) {
        cnt[adj[i][j]]++;
      }
    }
    priority_queue<pii,vector<pii>,greater<pii>> p;
    for (int i=1;i<=n;i++) {
      p.push(mp(cnt[i],i));
    }
    memset (cnt,0,sizeof(cnt));
    queue<int> ans;
    while (!p.empty()) {
      int cur=p.top().se;
      ans.push(cur);
      for (int i=0;i<adj[cur].size();i++) {
        cnt[adj[cur][i]]++;
      }
      p.pop();
      cur=p.top().se;
      if (p.top().fi==0) {
        ans.push(cur);
        for (int i=0;i<adj[cur].size();i++) {
          cnt[adj[cur][i]]++;
        }
        p.pop();
      }
      queue<pii> q;
      while (!p.empty()) {
        pii now=p.top();
        if (cnt[now.se]>0) {
          now.fi-=cnt[now.se];
          cnt[now.se]=0;
        }
        p.pop();
        q.push(now);
      }
      while (!q.empty()) {
        p.push(q.front());
        q.pop();
      }
      cout << ans.size() << " ";
      while (!ans.empty()) {
        cout << ans.front() << " ";
        ans.pop();
      }
      cout << endl;
    }
    return 0;
}
