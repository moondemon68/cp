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
    int a,b,c,d;
    cin >> a >> b;
    int g=__gcd(a,b);
    vector<int> x;
    for (int i=1;i*i<=g;i++) {
      if (g%i==0) x.pb(i);
      if (i*i!=g) x.pb(g/i);
    }
    sort (x.begin(),x.end());
    int q;
    cin >> q;
    for (int i=1;i<=q;i++) {
      int c,d;
      cin >> c >> d;
      int l=0,r=x.size(),ans=-1;
      while (l<=r) {
        int m=(l+r)/2;
        if (x[m]>=c&&x[m]<=d) {
          ans=x[m];
          l=m+1;
        } else if (x[m]<c) {
          l=m+1;
        } else if (x[m]>d) {
          r=m-1;
        }
      }
      cout << ans << endl;
    }
    return 0;
}
