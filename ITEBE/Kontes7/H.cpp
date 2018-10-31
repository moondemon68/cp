#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define LL long long

using namespace std;

long long n,k,x;
long long dp[100005][2];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> k >> x;
    memset (dp,-1,sizeof(dp));
    dp[1][0]=1;
    dp[1][1]=0;
    dp[2][0]=0;
    dp[2][1]=1;
    for (int i=3;i<=n;i++) {
        dp[i][0]=(k-1)*dp[i-1][1];
        dp[i][0]%=MOD;
        dp[i][1]=dp[i-1][0]+(k-2)*dp[i-1][1];
        dp[i][1]%=MOD;
    }
    //for (int i=1;i<=n;i++) cout << dp[i][0] << " " << dp[i][1] << endl;
    if (x==1) x=0;
    else x=1;
    cout << dp[n][x] << endl;
    return 0;
}
