#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define LL long long

using namespace std;

int b[200005][35];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc;
    cin >> tc;
    while (tc--) {
      memset (b,0,sizeof(b));
      int n;
      cin >> n;
      int a[200005];
      for (int i=1;i<=n;i++) {
        int x;
        cin >> x;
        int cnt=0;
        while (x>0) {
          b[i][cnt]=x%2;
          x/=2;
          cnt++;
        }
      }
      for (int i=1;i<=n;i++) {
        for (int j=0;j<=32;j++) {
          b[i][j]+=b[i-1][j];
        }
      }
      int q;
      cin >> q;
      while (q--){
        int l,r;
        cin >> l >> r;
        int ans=0;
        for (int i=0;i<=32;i++) {
          if ((b[r][i]-b[l-1][i])==r-l+1) ans+=pow(2,i);
        }
        cout << ans << endl;
      }
    }
    return 0;
}
