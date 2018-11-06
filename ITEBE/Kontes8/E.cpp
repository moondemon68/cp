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

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    int tc=1;
    while (1>0) {
      cin >> n;
      if (n==0) return 0;
      for (int i=1;i<=n;i++) cin >> s[i];
      map<string,int> id;
      for (int i=1;i<=n;i++) id[s[i]]=i;
      int m;
      cin >> m;
      vector<pair<pii,double> > edge;
      for (int i=1;i<=m;i++) {
        string u,v;
        double c;
        cin >> u >> c >> v;
        edge.pb(mp(mp(id[u],id[v]),-1*log(c)));
      }
      double dist[35];
      memset (dist,123456789,sizeof(dist));
      bool y=1;
      dist[1]=0;
      for (int i=1;i<n;i++) {
        for (int j=0;j<m;j++) {
          if (dist[edge[j].fi.se]>dist[edge[j].fi.fi]+edge[j].se) {
            dist[edge[j].fi.se]=dist[edge[j].fi.fi]+edge[j].se;
          }
        }
      }
      for (int i=0;i<m;i++) {
        //cout << dist[edge[i].fi.se]-dist[edge[i].fi.fi]-edge[i].se << endl;
        if (dist[edge[i].fi.se]>dist[edge[i].fi.fi]+edge[i].se) {
          y=0;
        }
      }
      cout << "Case " << tc << ": ";
      if (!y) cout << "Yes" << endl;
      else cout << "No" << endl;
      tc++;
    }
    return 0;
}
