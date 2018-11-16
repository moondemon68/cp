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
    int n;
    double t,l=0,dist=0;
    cin >> n >> t;
    double d[1005],s[1005];
    for (int i=1;i<=n;i++) {
      cin >> d[i] >> s[i];
      dist+=d[i];
      l=min(l,-1*s[i]);
    }

    double ans=0,r=1234567;
    while (l<r) {
      double c=(l+r)/2;
      double time=0;
      bool x=0;
      for (int i=1;i<=n;i++) {
        if (d[i]/(s[i]+c)<=0) {
          x=1;
        }
        time+=d[i]/(s[i]+c);
      }
      //cout << fixed << setprecision(8) << time << " ";
      if (x) {
        l=c+0.0000000001;
      } else if (time<t) {
        r=c-0.0000000001;
      }
      else {
        ans=c;
        l=c+0.0000000001;
      }
      //cout << fixed << setprecision(8) << c << endl;
    }
    cout << fixed << setprecision(12) << ans << endl;
    return 0;
}
