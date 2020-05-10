#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 100000000
#define pii pair<int,int>
#define LL long long
using namespace std;

LL dp[105][105][15][15];
int K1, K2;

LL solve(int n1, int n2, int k1, int k2) {
    if (n1 < 0 || n2 < 0 || k1 < 0 || k2 < 0) return 0;
    if (n1 == 0 && n2 == 0) return 1;
    if (dp[n1][n2][k1][k2] != -1) return dp[n1][n2][k1][k2];
    return dp[n1][n2][k1][k2] = (solve(n1-1, n2, k1-1, K2) + solve(n1, n2-1, K1, k2-1)) % MOD; 
}

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n1, n2;
    cin >> n1 >> n2 >> K1 >> K2;
    memset (dp,-1,sizeof(dp));
    cout << solve(n1,n2,K1,K2) << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}