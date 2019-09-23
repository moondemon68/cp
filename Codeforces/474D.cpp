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
    int tc,k;
    cin >> tc >> k;
    LL dp[100005];
    memset (dp,0,sizeof(dp));
    dp[0]=0;
    for (int i=1;i<=k;i++) dp[i]=1;
    dp[k]++;
    for (int i=k+1;i<=100000;i++) {
        dp[i]=dp[i-1]+dp[i-k];
        dp[i]%=MOD;
    }
    for (int i=1;i<=100000;i++) {
        dp[i]+=dp[i-1];
        dp[i]%=MOD;
    }
    while (tc--) {
        int x,y;
        cin >> x >> y;
        LL ans = (dp[y]-dp[x-1])%MOD;
        if (ans<0) ans+=MOD;
        cout << ans << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}