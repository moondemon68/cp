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
    int m,n;
    cin >> m >> n;
    vector<int> adj[30];
    for (int i=1;i<=m;i++) {
      char a,b;
      cin >> a >> b;
      adj[a-'a'].pb(b-'a');
    }
    for (int i=1;i<=n;i++) {
      string s,t;
      cin >> s >> t;
      if (s.size()!=t.size()) {
        cout << "no" << endl;
        continue;
      }
      bool y=1;
      for (int j=0;j<s.size();j++) {
        int a=s[j]-'a',b=t[j]-'a';
        bool vis[30];
        memset (vis,0,sizeof(vis));
        vis[a]=1;
        stack<int> p;
        p.push(a);
        while (!p.empty()) {
          int cur=p.top();
          p.pop();
          for (int k=0;k<adj[cur].size();k++) {
            int next=adj[cur][k];
            if (!vis[next]) {
              vis[next]=1;
              p.push(next);
            }
          }
        }
        if (!vis[b]) y=0;
      }
      if (y) cout << "yes" << endl; else cout << "no" << endl;
    }
    return 0;
}
