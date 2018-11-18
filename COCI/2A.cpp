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
    vector<pair<int,int> > a;
    int n,m;
    cin >> n;
    for (int i=1;i<=n;i++) {
      int x;
      cin >> x;
      a.pb(mp(x,0));
    }
    cin >> m;
    for (int i=1;i<=m;i++) {
      int x;
      cin >> x;
      a.pb(mp(x,1));
    }
    sort (a.begin(),a.end());
    int t=0,sa=0,sb=0,ans=0,w=-1,cnt=0;
    bool y=0;
    for (int i=0;i<a.size();i++) {
      if (a[i].fi<=1440) cnt++;
      if (a[i].se==0) sa++;
      else if (a[i].se==1) sb++;
      if (w==-1) {
        if (sa>sb) w=0;
        else w=1;
      } else {
        if (sa>sb&&w==1) {
          w=0;
          ans++;
        } else if (sa<sb&&w==0) {
          w=1;
          ans++;
        }
      }
    }
    cout << cnt << endl;
    cout << ans << endl;
    return 0;
}
