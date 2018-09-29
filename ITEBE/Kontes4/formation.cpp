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
    LL n,m;
    cin >> n >> m;
    LL ans=2000000000000000000;
    for (int i=1;i*i<=n+m;i++) {
      cout << i << endl;
      if ((n+m)%i==0) {
        ans=min(ans,2*(i+(n+m)/i));
      }
    }
    cout << ans << endl;
    return 0;
}
