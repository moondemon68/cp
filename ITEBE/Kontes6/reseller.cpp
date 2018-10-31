#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define LL long long

using namespace std;

int n,m,v[3005],w[3005],p[3005],t[3005],dp[3005][3005];

int solve(int posi,int rem) {
  if (posi==0||rem==0) return 0;
  if (dp[posi][rem]!=-1) return dp[posi][rem];
  int ret=solve(posi-1,rem);
  if (rem>=w[posi]) ret=max(ret,solve(posi-1,rem-w[posi])+v[posi]);
  dp[posi][rem]=ret;
  return ret;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for (int i=1;i<=n;i++) cin >> v[i];
    for (int i=1;i<=n;i++) cin >> w[i];
    for (int i=1;i<=m;i++) cin >> p[i];
    for (int i=1;i<=m;i++) cin >> t[i];
    memset (dp,-1,sizeof(dp));
    int ans=0;
    for (int i=1;i<=m;i++) {
      ans=max(ans,solve(n,t[i])-p[i]);
    }
    cout << ans << endl;
    return 0;
}
/*
5 3
2 2 2 2 2
1 1 1 1 1
3 8 5
3 5 1
*/
