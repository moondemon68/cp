#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define INF 1234567890
#define pii pair<LL,LL>
#define LL long long
using namespace std;

LL r[205], g[205], bl[205];
LL dp[205][205][205];

LL solve(LL a, LL b, LL c) {
    if (a < 0 || b < 0 || c < 0) return INT_MIN;
    if (dp[a][b][c] != -1) return dp[a][b][c];
    LL ans = 0;
    if (a >= 1 && b >= 1) ans = max(ans, solve(a-1, b-1, c) + r[a] * g[b]);
    if (a >= 1 && c >= 1) ans = max(ans, solve(a-1, b, c-1) + r[a] * bl[c]);
    if (b >= 1 && c >= 1) ans = max(ans, solve(a, b-1, c-1) + g[b] * bl[c]);
    return dp[a][b][c] = ans;
}

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    LL R,G,B;
    cin >> R >> G >> B;
    for (LL i=1;i<=R;i++) cin >> r[i];
    for (LL i=1;i<=G;i++) cin >> g[i];
    for (LL i=1;i<=B;i++) cin >> bl[i];
    sort (r+1,r+R+1);
    sort (g+1,g+G+1);
    sort (bl+1,bl+B+1);
    
    memset(dp,-1,sizeof(dp));

    cout << solve(R, G, B) << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}