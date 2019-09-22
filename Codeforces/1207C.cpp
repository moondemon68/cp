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
    LL tc;
    cin >> tc;
    while (tc--) {
        LL n,a,b;
        cin >> n >> a >> b;
        string s;
        cin >> s;
        LL dp[n+5][2];
        for (LL i=0;i<=n;i++) {
            dp[i][0] = 4e18+5;
            dp[i][1] = 4e18+5;
        }
        dp[0][0] = b;
        for (LL i=0;i<n;i++) {
            if (s[i]=='0') {
                dp[i+1][0] = min(dp[i+1][0], dp[i][0]+a+b);
                dp[i+1][1] = min(dp[i+1][1], dp[i][0]+2*a+2*b);
                dp[i+1][0] = min(dp[i+1][0], dp[i][1]+2*a+b);
                dp[i+1][1] = min(dp[i+1][1], dp[i][1]+a+2*b);
            } else {
                dp[i+1][1] = min(dp[i+1][1], dp[i][1]+a+2*b);
            }
        }
        cout << dp[n][0] << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}