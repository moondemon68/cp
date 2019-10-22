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
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int r,c;
    cin >> r >> c;
    int a[r+5][c+5];
    int dp[r+5][c+5];
    memset (dp,0,sizeof(dp));
    memset (a,0,sizeof(a));
    for (int i=1;i<=r;i++) {
        for (int j=1;j<=c;j++) {
            cin >> a[i][j];
        }
    }
    dp[r][c]=1;
    for (int i=r-1;i>=1;i--) {
        dp[i][c]=max(dp[i+1][c]-a[i][c],1);
    }
    for (int i=c-1;i>=1;i--) {
        dp[r][i]=max(dp[r][i+1]-a[r][i],1);
    }
    for (int i=r-1;i>=1;i--) {
        for (int j=c-1;j>=1;j--) {
            dp[i][j]=max(min(dp[i+1][j],dp[i][j+1])-a[i][j],1);
        }
    }
    // for (int i=1;i<=r;i++) {
    //     for (int j=1;j<=c;j++) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    cout << dp[1][1] << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}