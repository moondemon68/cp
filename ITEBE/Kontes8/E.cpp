#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define LL long long

using namespace std;

string s[35];
map<string,int> id;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for (int i=1;i<=n;i++) cin >> s[i];
    for (int i=1;i<=n;i++) id[s[i]]=i;
    int m;
    cin >> m;
    vector<pair<double,int> > adj[35];
    for (int i=1;i<=m;i++) {
      string u,v;
      double c;
      cin >> u >> c >> v;
      adj[id[u]].pb(mp(log(c),id[v]));
    }
    for (int i=1;i<=n;i++) {
      for (int j=0;j<adj[i].size();j++) {
        cout << adj[i][j].fi << endl;
      }
    }
    double dist[35];
    memset (dist,INT_MAX,sizeof(dist));
    bool y=1;
    dist[1]=0;
    for (int i=1;i<n;i++) {
      for (int j=0;j<adj[i].size();j++) {
        if (dist[i]+adj[i][j].fi<dist[adj[i][j].se]) {
          //cout << dist[adj[i][j].se] << endl;
          if (dist[adj[i][j].se]<0) {
            y=0;
            break;
          }
          dist[adj[i][j].se]=dist[i]+adj[i][j].fi;
        }
      }
      if (!y) break;
    }
    for (int i=1;i<=n;i++) {
      cout << dist[i] << " ";
    }
    if (y) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}
