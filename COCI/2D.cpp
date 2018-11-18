#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define LL long long

using namespace std;

int r,c,g,h;
int dp[105][105][1005],p[105][105];
bool inside(int a,int b) {
  return a>=1&&a<=r&&b>=1&&b<=c;
}

int solve(int a,int b,int rem) {
  if (!inside(a,b)) return -123456789;
  if (a==g&&b==h&&rem==0) return 0;
  if (rem<0) return -123456789;
  if (dp[a][b][rem]!=-1) return dp[a][b][rem];
  int ret=0;
  ret=max(ret,solve(a+1,b,rem-1)+p[a][b]);
  ret=max(ret,solve(a-1,b,rem-1)+p[a][b]);
  ret=max(ret,solve(a,b+1,rem-1)+p[a][b]);
  ret=max(ret,solve(a,b-1,rem-1)+p[a][b]);
  return dp[a][b][rem]=ret;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> r >> c;
    cin >> g >> h;
    int k;
    cin >> k;
    memset (dp,-1,sizeof(dp));
    for (int i=1;i<=r;i++) {
      for (int j=1;j<=c;j++) {
        cin >> p[i][j];
      }
    }
    cout << solve(g,h,k) << endl;
    return 0;
}
