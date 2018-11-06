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
      int n;
      cin >> n;
      int a[1005],b[1005];
      for (int i=1;i<=n;i++) cin >> a[i];
      for (int i=1;i<=n;i++) cin >> b[i];
      sort (a+1,a+n+1);
      sort (b+1,b+n+1);
      int ans=0;
      for (int i=1;i<=n;i++) ans+=a[i]*b[i];
      cout << ans << endl;
    }
    return 0;
}
