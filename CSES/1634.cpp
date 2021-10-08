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
    int n,x;
    cin >> n >> x;
    int a[n+5];
    for (int i=1;i<=n;i++) cin >> a[i];
    int dp[x+5];
    for (int i=1;i<=x;i++) dp[i] = MOD;
    dp[0] = 0;
    for (int i=1;i<=x;i++) {
        for (int j=1;j<=n;j++) {
            if (i-a[j] >= 0) {
                dp[i] = min(dp[i], dp[i-a[j]] + 1);
            }
        }
    }
    if (dp[x] == MOD) cout << -1 << endl; else cout << dp[x] << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}