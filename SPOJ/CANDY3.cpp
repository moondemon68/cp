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
      LL ans=0;
      for (LL i=1;i<=n;i++) {
        LL x;
        cin >> x;
        ans+=x;
        ans%=n;
      }
      if (ans%n==0) cout << "YES" << endl;
      else cout << "NO" << endl;
    }
    return 0;
}
