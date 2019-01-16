#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define LL long long

using namespace std;

int a[100005],b[100005],c[100005],dp[100005][4];

int solve(int x,int type) {
    if (x<0) return -1*MOD;
    if (x==0) return 0;
    if (dp[x][type]!=-1) return dp[x][type];
    if (type==1) {
        return dp[x][type]=max(solve(x-1,2)+b[x],solve(x-1,3)+c[x]);
    } else if (type==2) {
        return dp[x][type]=max(solve(x-1,1)+a[x],solve(x-1,3)+c[x]);
    } else if (type==3) {
        return dp[x][type]=max(solve(x-1,1)+a[x],solve(x-1,2)+b[x]);
    } else {
        return dp[x][type]=max(max(solve(x-1,1)+a[x],solve(x-1,2)+b[x]),solve(x-1,3)+c[x]);
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for (int i=1;i<=n;i++) cin >> a[i] >> b[i] >> c[i];
    memset (dp,-1,sizeof(dp));
    cout << solve(n,0) << endl;
    return 0;
}
