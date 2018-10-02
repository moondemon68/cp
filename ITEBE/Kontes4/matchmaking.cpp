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
    int n,a,b;
    cin >> n >> a >> b;
    vector<pii> m,f;
    for (int i=1;i<=n;i++) {
      int x,y;
      char c;
      cin >> x >> y >> c;
      if (c=='M') {
        m.pb(mp(y,x));
      } else if (c=='F') {
        f.pb(mp(y,x));
      }
    }
    sort (m.begin(),m.end());
    sort (f.begin(),f.end());

    int maxm=-1,maxf=-1;
    for (int i=0;i<m.size();i++) {
      //cout << m[i].fi << " " << m[i].se << endl;
      if (m[i].fi<=a) maxm=max(maxm,m[i].se);
    }
    //cout << endl;
    for (int i=0;i<f.size();i++) {
      //cout << f[i].fi << " " << f[i].se << endl;
      if (f[i].fi<=b) maxf=max(maxf,f[i].se);
    }
    int ans=0;
    if (maxm>-1&&maxf>-1) ans=maxm+maxf;

    if (m.size()>1) {
      for (int i=0;i<m.size();i++) {
        for (int j=i+1;j<m.size();j++) {
          if (m[i].fi+m[j].fi>a) break;
          else ans=max(ans,m[i].se+m[j].se);
        }
      }
    }

    if (f.size()>1) {
      for (int i=0;i<f.size();i++) {
        for (int j=i+1;j<f.size();j++) {
          if (f[i].fi+f[j].fi>b) break;
          else ans=max(ans,f[i].se+f[j].se);
        }
      }
    }

    cout << ans << endl;
    return 0;
}
