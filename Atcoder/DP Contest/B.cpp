#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define LL long long

using namespace std;

int a[100005],dp[100005],k;
int solve(int x) {
    if (x<1) return MOD;
    if (x==1) return 0;
    if (dp[x]!=-1) return dp[x];
    int ans=MOD;
    for (int i=1;i<=k;i++) {
        if ((x-i)>=1) ans=min(ans,solve(x-i)+abs(a[x]-a[x-i]));
    }
    return dp[x]=ans;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n >> k;
    for (int i=1;i<=n;i++) cin >> a[i];
    memset (dp,-1,sizeof(dp));
    cout << solve(n) << endl;
    return 0;
}
