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
    LL n;
    cin >> n;
    LL a[n+5];
    for (LL i=1;i<=n;i++) cin >> a[i];
    LL cnt[100005];
    memset (cnt,0,sizeof(cnt));
    for (LL i=1;i<=n;i++) cnt[a[i]]++;
    LL dp[100005];
    memset (dp,0,sizeof(dp));
    dp[1]=cnt[1];
    for (LL i=2;i<=100000;i++) {
        dp[i]=max(dp[i-1],dp[i-2]+cnt[i]*i);
    }
    cout << dp[100000] << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}