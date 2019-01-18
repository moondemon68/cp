#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define LL long long

using namespace std;

int a[205],b[205],dp[205][2][2][205];
int solve(int pos,int cana,int canb,int rem) {
    if (pos==0&&rem>0) return -1*MOD;
    if (pos==0&&rem==0) return 0;
    if (dp[pos][cana][canb][rem]!=-1) return dp[pos][cana][canb][rem];
    if (cana==1&&canb==1) {
        return dp[pos][cana][canb][rem]=max(solve(pos-1,1,1,rem),max(solve(pos-1,0,1,rem-1)+a[i],solve(pos-1,1,0,rem-1)+b[i]));
    } 
    if (cana==0&&canb==1) {
        return dp[pos][cana][canb][rem]=max(solve(pos-1,0,1,rem),max(solve(pos-1,0,1,rem-1)+a[i],solve(pos-1,1,0,rem-1)+b[i]));
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,k;
    while (cin >> n >> k) {
        if (n==0) return 0;
        memset (a,0,sizeof(a));
        memset (b,0,sizeof(b));
        memset (dp,-1,sizeof(dp));
        for (int i=1;i<=n;i++) cin >> a[i] >> b[i];
        cout << solve(n,1,1,k) << endl;
    }    
    return 0;
}
