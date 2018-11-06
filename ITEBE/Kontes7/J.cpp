#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define LL long long
//__buildin_popcount(7)
using namespace std;

string s;
int k;
int dp[1005][1005];   

int solve(int n,int m) {
    if (n==k) return 1;
    if (dp[n][m]!=-1) return dp[n][m];

}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> s >> k;
    memset (dp,-1,sizeof(dp));
    dp[1][0]=1;
    dp[1][1]=1;

    return 0;
}
