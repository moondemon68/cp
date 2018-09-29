#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define LL long long

using namespace std;

int a[1000005];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for (int i=1;i<=n;i++) cin >> a[i];
    int l=1,r=1000000007,ans=0;
    while (l<=r) {
      int m=(l+r)/2;
      int s=m;
      bool y=1;
      for (int i=1;i<n;i++) {
        int d=a[i+1]-a[i];
        if (d==s) {
          s--;
        } else if (d>s) {
          y=0;
          break;
        }
      }
      if (!y) {
        l=m+1;
      } else {
        ans=m;
        r=m-1;
      }
    }
    cout << ans << endl;
    return 0;
}
