#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define LL long long

using namespace std;

int a[100005];
int dp[100005];

int solve(int x) {
    if (x<1) return 10000000;
    if (x==1) return 0;
    if (dp[x]!=-1) return dp[x];
    return dp[x]=min(solve(x-1)+abs(a[x]-a[x-1]),solve(x-2)+abs(a[x]-a[x-2]));
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for (int i=1;i<=n;i++) cin >> a[i];    
    memset (dp,-1,sizeof(dp));
    cout << solve(n) << endl;
    return 0;
}
