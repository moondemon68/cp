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

int dp[505][505];

int solve(int x, int y) {
    if (x > y) swap(x, y);
    if (x <= 0 || y <= 0) return MOD;
    if (x == y) return 0;
    if (dp[x][y] != -1) return dp[x][y];
    int ans = MOD;
    for (int i=1;i<y;i++) {
        ans = min(ans, solve(x, i) + solve(x, y-i) + 1);
    }
    for (int i=1;i<x;i++) {
        ans = min(ans, solve(i, y) + solve(x-i, y) + 1);
    }
    return dp[x][y] = ans;
}

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int a,b;
    cin >> a >> b;
    if (a > b) swap(a, b);
    memset (dp,-1,sizeof(dp));
    for (int i=1;i<=500;i++) {
        dp[i][i] = 0;
    }
    cout << solve(a,b) << endl;
    // for (int i=1;i<=a;i++) {
    //     for (int j=1;j<=b;j++) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}