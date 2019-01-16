#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define LL long long

using namespace std;

LL v[105],w[105],dp[105][100005];

LL solve(int pos,int rem) {
    if (rem<0) return INT_MAX;
    if (pos<0) return INT_MAX;
    if (rem==0) return 0;
    if (dp[pos][rem]!=-1) return dp[pos][rem];
    return dp[pos][rem]=min(solve(pos-1,rem),solve(pos-1,rem-v[pos])+w[pos]);
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    LL m;
    cin >> n >> m;
    for (int i=1;i<=n;i++) cin >> w[i] >> v[i];  
    memset(dp,-1,sizeof(dp));
    int ans=0;
    for (int i=1;i<=100000;i++) {
        if (solve(n,i)<=m) ans=i;
    }
    cout << ans << endl;  
    return 0;
}
