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
    int a[n+5],dp[n+5];
    for (int i=1;i<=n;i++) cin >> a[i];
    dp[1]=1;
    for (int i=2;i<=n;i++) {
        if (a[i]>a[i-1]) dp[i]=dp[i-1]+1; else dp[i]=1;
    }
    int ans=0;
    for (int i=1;i<=n;i++) ans=max(ans,dp[i]);
    cout << ans << endl;
    return 0;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}