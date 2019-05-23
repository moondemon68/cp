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
    int n;
    cin >> n;
    int a[n+5];
    for (int i=1;i<=n;i++) cin >> a[i];
    int dp[n+5][3];
    memset (dp,-1,sizeof(dp));
    for (int i=0;i<=2;i++) dp[0][i]=0;
    for (int i=1;i<=n;i++) {
        dp[i][0]=max(dp[i-1][0],max(dp[i-1][1],dp[i-1][2]));
        if (a[i]==1||a[i]==3) dp[i][1]=max(dp[i-1][0]+1,dp[i-1][2]+1); 
        if (a[i]==2||a[i]==3) dp[i][2]=max(dp[i-1][0]+1,dp[i-1][1]+1);
    }
    cout << n-max(dp[n][0],max(dp[n][1],dp[n][2])) << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}