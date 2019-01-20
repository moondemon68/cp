#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define LL long long

using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,l,r;
    cin >> n >> l >> r;
    int mod0,mod1,mod2;
    if (r%3==0) {
        mod0=r/3;
        mod1=mod0;
        mod2=mod1;
    } else if (r%3==1) {
        mod0=r/3;
        mod1=mod0+1;
        mod2=mod0;
    } else if (r%3==2) {
        mod0=r/3;
        mod1=mod0+1;
        mod2=mod0+1;
    }
    if ((l-1)%3==0) {
        int x=(l-1)/3;
        mod0-=x;
        mod1-=x;
        mod2-=x;
    } else if ((l-1)%3==1) {
        int x=(l-1)/3;
        mod0-=x;
        mod1-=x+1;
        mod2-=x;
    } else if ((l-1)%3==2) {
        int x=(l-1)/3;
        mod0-=x;
        mod1-=x+1;
        mod2-=x+1;
    }
    LL dp[n+5][3];
    memset (dp,0,sizeof(dp));
    dp[1][0]=mod0;
    dp[1][1]=mod1;
    dp[1][2]=mod2;
    for (int i=2;i<=n;i++) {
        dp[i][0]=((dp[i-1][0]*mod0+dp[i-1][1]*mod2)%MOD+dp[i-1][2]*mod1)%MOD;
        dp[i][1]=((dp[i-1][2]*mod2+dp[i-1][1]*mod0)%MOD+dp[i-1][0]*mod1)%MOD;
        dp[i][2]=((dp[i-1][1]*mod1+dp[i-1][0]*mod2)%MOD+dp[i-1][2]*mod0)%MOD;
    }
    
    cout << dp[n][0];
    return 0;
}
