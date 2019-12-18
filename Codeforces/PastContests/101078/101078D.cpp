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
    int tc;
    cin >> tc;
    while (tc--) {
      LL n;
      cin >> n;
      LL ans=(n+1)/2;
      LL l=1,h=n,a=0;
      while (l<=h) {
        LL m=(l+h)/2;
        LL num=2*m-1;
        if (3*num+1<=n) {
          a=m;
          l=m+1;
        } else {
          h=m-1;
        }
      }
      cout << ans+(n+1)/2-a << endl;
    }
    return 0;
}
