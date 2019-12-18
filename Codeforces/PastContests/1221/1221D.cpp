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
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        LL a[n+5],b[n+5];
        for (int i=1;i<=n;i++) cin >> a[i] >> b[i];
        LL dp[n+5][5];
        memset (dp,0,sizeof(dp));
        for (int i=1;i<=n;i++) {
            for (int j=0;j<=3;j++) {
                dp[i][j]=1e18+5;
                if (i==1) dp[i][j]=b[i]*j;
                else {
                    for (int k=0;k<=3;k++) {
                        if (a[i-1]+k!=a[i]+j) {
                            dp[i][j]=min(dp[i][j],b[i]*j+dp[i-1][k]);
                        }
                    }
                }
                //cout << dp[i][j] <<  " ";
            }
            //cout << endl;
        }
        LL ans=dp[n][0];
        for (int i=1;i<=3;i++) ans=min(ans,dp[n][i]);
        cout << ans << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}