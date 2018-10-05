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
    vector<int> mm,mf;
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
      if (m[i].fi<=a) maxm=max(maxm,m[i].se);
      if (i>0) mm.pb(max(m[i].se,mm[i-1]));
      else mm.pb(m[i].se);
    }
    for (int i=0;i<mm.size();i++) cout << mm[i] << " ";
    cout << endl;
    for (int i=0;i<f.size();i++) {
      if (f[i].fi<=b) maxf=max(maxf,f[i].se);
      if (i>0) mf.pb(max(f[i].se,f[i-1].se));
      else mf.pb(f[i].se);
    }
    int ans=0;
    if (maxm>-1&&maxf>-1) ans=maxm+maxf;

    if (m.size()>1) {
      for (int i=0;i<m.size();i++) {
        int l=0,h=m.size()-1,c=l;
        while(l<=h) {
          int mid=(l+h)/2;
          if (m[i].fi+m[mid].fi>a) {
            h=mid-1;
          } else {
            c=mid;
            l=mid+1;
          }
        }
        cout << i << c << endl;
        if (i==c) continue;
        if (m[i].fi==m[c].fi&&m[i].se==m[c].se) c--;
        if (c<0||m[i].fi+m[c].fi>a) continue;
        ans=max(ans,m[i].se+mm[c]);
      }
    }

    if (f.size()>1) {
      for (int i=0;i<f.size();i++) {
        int l=0,h=f.size()-1,c=l;
        while(l<=h) {
          int mid=(l+h)/2;
          if (f[i].fi+f[mid].fi>b) {
            h=mid-1;
          } else {
            c=mid;
            l=mid+1;
          }
        }
        if (f[i].fi==f[c].fi&&f[i].se==f[c].se) c--;
        if (c<0||f[i].fi+f[c].fi>b) continue;
        ans=max(ans,f[i].se+mf[c]);
      }
    }

    cout << ans << endl;
    return 0;
}
/*
5 15 3
1 6 M
1 5 M
1 9 M
4 8 M
5 7 M
*/
