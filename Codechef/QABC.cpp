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
      int a[100005],b[100005];
      for (int i=1;i<=n;i++) cin >> a[i];
      for (int i=1;i<=n;i++) cin >> b[i];
      bool y=1;
      for (int i=1;i<=n-2;i++) {
        if (a[i]<b[i]) {
          int d=b[i]-a[i];
          a[i]+=d;
          a[i+1]+=d*2;
          a[i+2]+=d*3;
        } else if (a[i]>b[i]) {
          y=0;
          break;
        }
      }
      //for (int i=1;i<=n;i++) cout << a[i] << ' ';
      if (a[n]!=b[n]) y=0;
      if (a[n-1]!=b[n-1]) y=0;
      if (y) cout << "TAK" << endl;
      else cout << "NIE" << endl;
    }
    return 0;
}
