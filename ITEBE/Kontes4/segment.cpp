#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<LL,LL>
#define LL long long

using namespace std;

int a[1000005];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    LL n;
    int b,c;
    cin >> n >> b >> c;
    for (int i=1;i<=n;i++) cin >> a[i];
    sort (a+1,a+n+1);
    LL ans=0;
    a[0]=0;
    for (int i=1;i<=n;i++) {
      int l=0,r=n,cand=l;
      while (l<=r) {
        int m=(l+r)/2;
        int d=a[m]/b-(a[i]-1)/b;
        if (d<c) {
          l=m+1;
        } else if (d>c) {
          r=m-1;
        } else {
          cand=m;
          l=m+1;
        }
      }
      int candl=0;
      l=0;r=n;
      while (l<=r) {
        int m=(l+r)/2;
        int d=a[m]/b-(a[i]-1)/b;
        if (d<c) {
          candl=m;
          l=m+1;
        } else if (d>=c) {
          r=m-1;
        }
      }
      //cout << i << " " << candl << " " << cand << endl;
      ans+=(LL)max(cand-candl,0);
      //cout << i << " " << cand << endl;
      //for (int j=i;j<=cand;j++) {
      //  LL d=a[j]/b-(a[i]-1)/b;
      //  if (d==c) ans++;
      //}
    }
    cout << ans << endl;
    return 0;
}
/*
9 3 2
1 2 3 4 5 6 7 8 9
*/
