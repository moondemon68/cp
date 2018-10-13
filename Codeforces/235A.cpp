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
    LL n;
    cin >> n;
    if (n==1) cout << 1 << endl;
    else if (n==2) cout << 2 << endl;
    else if (n%2==1) cout << n*(n-1)*(n-2) << endl;
    else {
      LL ans=(n-1)*(n-2)*(n-3);
      for (int i=max(1LL,n-50);i<=n;i++) {
        for (int j=max(1LL,n-50);j<=n;j++) {
          for (int k=max(1LL,n-50);k<=n;k++) {
            LL a=i,b=j,c=k;
            a=(a*b)/__gcd(a,b);
            a=(a*c)/__gcd(a,c);
            ans=max(ans,a);
          }
        }
      }
      cout << ans << endl;
    }
    return 0;
}
