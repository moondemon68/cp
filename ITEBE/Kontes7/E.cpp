#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define LL long long

using namespace std;

int n;
int a[1005],dp[1005][1005];

int solve(int l,int r) {
  if (l>r) return 0;
  if (dp[l][r]!=-1) return dp[l][r];
  return dp[l][r]=max(min(solve(l+2,r),solve(l+1,r-1))+a[l],min(solve(l+1,r-1),solve(l,r-2))+a[r]);
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (int i=1;i<=n;i++) cin >> a[i];
    memset(dp,-1,sizeof(dp));
    cout << solve(1,n) << endl;
    return 0;
}
