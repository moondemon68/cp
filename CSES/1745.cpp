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

bool dp[105][100005];
int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    int a[n+5];
    for (int i=1;i<=n;i++) cin >> a[i];
    sort (a+1,a+n+1);
    memset (dp,0,sizeof(dp));
    dp[0][0] = 1;
    for (int i=1;i<=n;i++) {
        for (int j=0;j<=100000;j++) {
            if (j-a[i] >= 0) dp[i][j] |= dp[i-1][j-a[i]];
            dp[i][j] |= dp[i-1][j];
        }
    }
    vector<int> ans;
    for (int i=1;i<=100000;i++) {
        if (dp[n][i]) ans.pb(i);
    }
    cout << ans.size() << endl;
    for (auto x : ans) cout << x << " ";
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}