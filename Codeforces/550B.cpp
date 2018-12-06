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
    int n,l,r,z;
    cin >> n >> l >> r >> z;
    int a[20];
    int ans=0;
    for (int i=0;i<n;i++) cin >> a[i];
    for (int i=0;i<(1<<n);i++) {
      int x=i;
      vector<bool> p;
      for (int j=0;j<n;j++) {
        p.pb(x%2);
        x/=2;
      }
      int tot=0,mini=INT_MAX,maxi=0,cnt=0;
      for (int j=0;j<n;j++) {
        if (p[j]) {
          cnt++;
          tot+=a[j];
          mini=min(a[j],mini);
          maxi=max(maxi,a[j]);
        }
      }
      if (cnt>=2&&tot>=l&&tot<=r&&maxi-mini>=z) {
        ans++;
      }
    }
    cout << ans << endl;
    return 0;
}
