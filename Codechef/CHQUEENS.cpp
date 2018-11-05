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
      int x,y,n,m;
      cin >> n >> m >> x >> y;
      int ans=0;
      for (int i=1;i<=n;i++) {
        for (int j=1;j<=m;j++) {
          for (int k=1;k<=n;k++) {
            for (int l=1;l<=m;l++) {
              if (i==j&&k==l) continue;
              if (i==k||j==l) continue;
              if (abs(i-k)==abs(j-l)) continue;
              ans++;
            }
          }
        }
      }
      cout << ans << endl;
    }
    return 0;
}
