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
    LL n,m,k;
    cin >> n >> m >> k;
    LL a[n+5];
    a[0]=0;
    for (LL i=1;i<=n;i++) cin >> a[i];
    for (LL i=2;i<=n;i++) a[i]+=a[i-1];
    LL dp[k+5][n+5];
    memset (dp,0,sizeof(dp));
    for (LL i=1;i<=k;i++) {
        for (LL j=1;j<=n;j++) {
            if (i*m>j || j-m<0) dp[i][j]=0;
            else {
                //cout << "." << dp[i][j-1] << "*" << dp[i-1][j-m]+a[j]-a[j-m] << endl;   
                dp[i][j]=max(dp[i][j-1],dp[i-1][j-m]+a[j]-a[j-m]);
            }
            //cout << dp[i][j] << " ";
        }
        //cout << endl;
    }
    cout << dp[k][n] << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}