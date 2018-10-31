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
    int n,m;
    cin >> n >> m;
    int a[305][305],dp[305][305];
    memset (a,0,sizeof(a));
    memset (dp,0,sizeof(dp));
    for (int i=1;i<=n;i++) {
      for (int j=1;j<=m;j++) {
        cin >> a[i][j];
      }
    }
    for (int i=1;i<=n;i++) {
      for (int j=1;j<=m;j++) {
        if (i==1&&j==1) dp[i][j]=a[i][j];
        else if (i==1) dp[i][j]=dp[i][j-1]+a[i][j];
        else if (j==1) dp[i][j]=dp[i-1][j]+a[i][j];
        else dp[i][j]=max(dp[i-1][j],dp[i][j-1])+a[i][j];
      }
    }
    int ans=0;
    int r=n,c=m;
    while (r!=0&&c!=0) {
      int rr=r,cc=c;
      if (dp[r-1][c]==dp[r][c]-a[r][c]) r--;
      else c--;
      ans+=a[rr][cc];
      a[rr][cc]=0;
    }
    memset (dp,0,sizeof(dp));
    for (int i=1;i<=n;i++) {
      for (int j=1;j<=m;j++) {
        //cout << a[i][j] << " ";
        if (i==1&&j==1) dp[i][j]=a[i][j];
        else if (i==1) dp[i][j]=dp[i][j-1]+a[i][j];
        else if (j==1) dp[i][j]=dp[i-1][j]+a[i][j];
        else dp[i][j]=max(dp[i-1][j],dp[i][j-1])+a[i][j];
      }
      //cout << endl;
    }
    r=n,c=m;
    while (r!=0&&c!=0) {
      int rr=r,cc=c;
      if (dp[r-1][c]==dp[r][c]-a[r][c]) r--;
      else c--;
      ans+=a[rr][cc];
      a[rr][cc]=0;
    }
    cout << ans << endl;
    return 0;
}

/*
3 4
1 6 1 5
7 3 10 1
2 8 −5 2
3 4
0 −6 1 5
0 0 0 0
2 8 −5 0
2 2
0 4
−1 0
*/
