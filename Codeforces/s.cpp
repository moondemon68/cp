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

int dp[100005];
int solve(int x) {
    if (x==0) return 0;
    if (dp[x]!=-1) return dp[x];
    int ret=1;
    for (int i=1;i<=x/2;i++) ret+=solve(x-i);
    return dp[x]=ret;
}

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    memset (dp,-1,sizeof(dp));
    dp[1]=1;
    for (int i=1;i<=10;i++) cout << solve(i) << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}