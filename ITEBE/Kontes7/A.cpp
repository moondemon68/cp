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
int a[2005];
int dp[2005][2005];

int solve(int l,int r) {
  if (l>r) return 0;
  if (dp[l][r]!=-1) return dp[l][r];
  int age=l+(n-r);
  return dp[l][r]=max(solve(l,r-1)+a[r]*age,solve(l+1,r)+a[l]*age);
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    memset (dp,-1,sizeof(dp));
    for (int i=1;i<=n;i++) {
      cin >> a[i];
    }
    cout << solve(1,n) << endl;
    return 0;
}
