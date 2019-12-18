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
    LL a[n+5],b[n+5];
    for (int i=1;i<=n;i++) cin >> a[i];
    for (int i=1;i<=n;i++) cin >> b[i];
    LL dp[n+5][2];
    memset (dp,0,sizeof(dp));
    dp[1][0]=a[1];
    dp[1][1]=b[1];
    dp[2][0]=b[1]+a[2];
    dp[2][1]=a[1]+b[2];
    for (int i=3;i<=n;i++) {
        dp[i][0]=a[i]+max(dp[i-1][1],dp[i-2][1]);
        dp[i][1]=b[i]+max(dp[i-1][0],dp[i-2][0]);
    }
    cout << max (dp[n][0],dp[n][1]) << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}