#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<LL,LL>
#define LL long long

using namespace std;

LL a[1000005];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    LL n,b,c;
    cin >> n >> b >> c;
    for (LL i=1;i<=n;i++) cin >> a[i];
    sort (a+1,a+n+1);
    LL ans=0;
    for (LL i=1;i<=n;i++) {
      LL l=i,r=n,cand=l;
      while (l<=r) {
        LL m=(l+r)/2;
        LL d=a[m]/b-a[i]/b;
        if (a[i]%b==0) d++;
        if (d<c) {
          l=m+1;
        } else if (d>c) {
          r=m-1;
        } else {
          cand=m;
          l=m+1;
        }
      }
      //cout << i << " " << cand << endl;
      for (int j=i;j<=cand;j++) {
        LL d=a[j]/b-(a[i]-1)/b;
        if (d==c) ans++;
      }
    }
    cout << ans << endl;
    return 0;
}
