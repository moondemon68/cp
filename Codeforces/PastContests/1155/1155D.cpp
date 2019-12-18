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
LL x;
LL dp[300005][3][3];

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> x;
    int a[n+5];
    for (int i=1;i<=n;i++) cin >> a[i];
    dp[0][0][0]=0;
    for (int i=1;i<=n;i++) {
        for (int j=0;j<=2;j++) {
            for (int k=0;k<=2;k++) {
                dp[i][j][k]=-12345678987654321;        
            }
        }
    }
    for (int i=0;i<=n;i++) {
        for (int j=0;j<=2;j++) {
            for (int k=0;k<=2;k++) {
                if (k<2) dp[i][j][k+1]=max(dp[i][j][k+1],dp[i][j][k]);
                if (j<2) dp[i][j+1][k]=max(dp[i][j+1][k],dp[i][j][k]);
                if (i<n) {
                    if (j==1) {
                        if (k==1) {
                            dp[i+1][j][k]=max(dp[i+1][j][k],dp[i][j][k]+a[i+1]*x);
                        } else {
                            dp[i+1][j][k]=max(dp[i+1][j][k],dp[i][j][k]+a[i+1]);
                        }
                    } else {
                        dp[i+1][j][k]=max(dp[i+1][j][k],dp[i][j][k]);
                    }
                } 
            }
        }
    }
    cout << dp[n][2][2] << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}