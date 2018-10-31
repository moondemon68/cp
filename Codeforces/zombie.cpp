#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<long long,long long>
#define LL long long

using namespace std;

bool cmp(pii a,pii b) {
  return a.fi-a.se>b.fi-b.se;
}

pair<LL,LL> a[200005];
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for (int i=1;i<=n;i++) cin >> a[i].fi >> a[i].se;
    sort (a+1,a+n+1,cmp);
    //for (int i=1;i<=n;i++) cout << a[i].fi << a[i].se << endl;
    //cout << a[n].fi+a[1].se << endl;
    LL l=1,h=123456789876543,ans=0;
    while (l<=h) {
      LL m=(l+h)/2,x=m;
      bool y=1;
      for (int i=1;i<=n;i++) {
        if (x<a[i].fi) {
          y=0;
          break;
        } else {
          x-=a[i].se;
        }
      }
      if (y) {
        ans=m;
        h=m-1;
      } else {
        l=m+1;
      }
    }
    cout << ans << endl;
    return 0;
}
