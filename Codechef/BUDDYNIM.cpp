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
      int n,m;
      cin >> n >> m;
      int a[105],b[105];
      for (int i=1;i<=n;i++) cin >> a[i];
      for (int i=1;i<=m;i++) cin >> b[i];
      bool y=1;
      for (int i=1;i<=n;i++) if (a[i]>0) {
        y=0;
        break;
      }
      for (int i=1;i<=m;i++) if (b[i]>0) {
        y=0;
        break;
      }
      if (y) cout << "Bob" << endl;
      else if (n!=m) cout << "Alice" << endl;
      else {
        y=1;
        for (int i=1;i<=n;i++) {
          if (a[i]!=b[i]) y=0;
        }
        if (y) cout << "Bob" << endl;
        else cout << "Alice" << endl;
      }
    }
    return 0;
}
