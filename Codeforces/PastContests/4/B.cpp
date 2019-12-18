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
    int n,t;
    cin >> n >> t;
    pii a[35];
    for (int i=1;i<=n;i++) cin >> a[i].fi >> a[i].se;
    int sum=0;
    int ans[35];
    memset (ans,0,sizeof(ans));
    for (int i=1;i<=n;i++) {
      ans[i]=a[i].se;
      sum+=ans[i];
    }
    int x=1;
    while (sum>t&&x<=n) {
      if (ans[x]>a[x].fi) {
        ans[x]--;
        sum--;
      } else x++;
    }
    if (x==n+1||sum<t) cout << "NO" << endl;
    else {
      cout << "YES" << endl;
      for (int i=1;i<=n;i++) cout << ans[i] << " ";
    }
    return 0;
}
