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
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    LL n,k,d;
    cin >> n >> k >> d;
    LL dp[n+5][2];
    memset (dp,0,sizeof(dp));
    dp[0][0]=1;
    for (LL i=1;i<=n;i++) {
        dp[i][0]=0;
        dp[i][1]=0;
        for (LL j=1;j<=k;j++) {
            if (i-j<0) break;
            if (j>=d) {
                dp[i][1]+=dp[i-j][0];
                dp[i][1]%=MOD;
                dp[i][1]+=dp[i-j][1];
                dp[i][1]%=MOD;
            } else {
                dp[i][0]+=dp[i-j][0];
                dp[i][0]%=MOD;
                dp[i][1]+=dp[i-j][1];
                dp[i][1]%=MOD;
            }
        }
    }
    cout << dp[n][1] << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}