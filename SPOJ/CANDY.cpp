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
    while (1>0) {
      int n;
      cin >> n;
      if (n==-1) return 0;
      int a[10005];
      int x=0;
      for (int i=1;i<=n;i++) {
        cin >> a[i];
        x+=a[i];
      }
      if (x%n!=0) cout << -1 << endl;
      else {
        x/=n;
        int ans=0;
        for (int i=1;i<=n;i++) {
          if (a[i]>x) ans+=a[i]-x;
        }
        cout << ans << endl;
      }
    }
    return 0;
}
