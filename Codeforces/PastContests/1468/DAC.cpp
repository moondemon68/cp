#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define INF 1234567890
#define pii pair<LL,LL>
#define LL long long
using namespace std;

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    LL tc;
    cin >> tc;
    while (tc--) {
      LL n,m,a2,b;
      cin >> n >> m >> a2 >> b;
      LL a[m+5];
      memset(a,0,sizeof(a));
      for (LL i=1;i<=m;i++) cin >> a[i];
      sort(a+1,a+m+1);
      // build(1,1,m);
      LL d;
      if (a2 < b) d = b - 1;
      else d = n - b;
      LL l = 0, h = min(m, abs(a2-b) - 1), ans = 0;
      LL maxwait = 0;
      for (int i=1;i<=h;i++) {
        maxwait = max(maxwait + 1, a[i]);
        // updateRange(1,1,m,1,i,1);
        if (maxwait < d) ans = i;
        // cout << i << " " << maxwait << endl;
        // for (int j=1;j<=m;j++) cout << queryRange(1,1,m,j,j) << " ";
        // cout << endl;
      }
      // cout << "d: " << d << endl;
      // cout << "h: " << h << endl;
      // cout << "ans: ";
      cout << ans << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}