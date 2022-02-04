#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define INF 1234567890
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
    LL dp[n+5];
    memset(dp,0,sizeof(dp));
    dp[0] = 1;
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=6;j++) {
            if (i-j >= 0) dp[i] += dp[i-j];
            dp[i] %= MOD;
        }
    }
    cout << dp[n] << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}