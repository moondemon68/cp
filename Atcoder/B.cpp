#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define LL long long

using namespace std;

LL a[1005];
vector<LL> x;
LL dp[100005][105];

LL solve(int n,int k) {
  if (n<-1||k<0) return -123456;
  if (n==-1&&k==0) return 0;
  if (n==-1&&k!=0) return -123456;
  if (dp[n][k]!=-1) return dp[n][k];
  else return dp[n][k]=max(solve(n-1,k),solve(n-1,k-1)&x[n]);
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,k;
    memset (dp,-1,sizeof(dp));
    cin >> n >> k;
    for (int i=1;i<=n;i++) cin >> a[i];
    for (int i=1;i<=n;i++) {
      LL sum=0;
      for (int j=i;j<=n;j++) {
        sum+=a[j];
        x.pb(sum);
      }
    }
    sort (x.begin(),x.end());
    for (int i=0;i<x.size();i++) cout << x[i] << " ";
    cout << endl;
    cout << solve(x.size()-1,k) << endl;
    return 0;
}
