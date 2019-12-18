#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<LL,LL>
#define LL long long

using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    LL n,m;
    cin >> n >> m;
    LL x[100005];
    for (LL i=1;i<=n+m;i++) cin >> x[i];
    bool d[100005];
    vector <LL> dr,ppl,ans;
    for (LL i=1;i<=n+m;i++) {
      cin >> d[i];
      if (d[i]) {
        dr.pb(x[i]);
        ans.pb(0);
      }
      else ppl.pb(x[i]);
    }
    dr.pb(INT_MAX);
    LL l=0,u=0,cnt=0;
    for (LL i=0;i<ppl.size();i++) {
      if (cnt==0) {
        u=(dr[cnt+1]+dr[cnt])/2;
      } else if (cnt==m-1) {
        l=(dr[cnt]+dr[cnt-1])/2;
        u=dr[cnt+1];
      } else {
        l=(dr[cnt]+dr[cnt-1])/2;
        u=(dr[cnt]+dr[cnt+1])/2;
      }
      //cout << cnt << " " << l << " " << u << endl;
      if (ppl[i]>=l&&ppl[i]<=u) {
        ans[cnt]++;
      } else {
        cnt++;
        if (cnt<=m) i--;
      }
    }
    for (LL i=0;i<m;i++) cout << ans[i] << " ";
    return 0;
}
