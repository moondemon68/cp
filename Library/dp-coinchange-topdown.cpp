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

int c[105],m,dp[100005];

int solve(int x) {
    if (x<0) return INF;
    if (x==0) return 0;
    if (dp[x]!=INF) return dp[x];
    int ret=INF;
    for (int i=1;i<=m;i++) {
        ret=min(ret,solve(x-c[i])+1);
    }
    return dp[x]=ret;
}

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> m;
    for (int i=1;i<=m;i++) cin >> c[i]; //input coins
    for (int i=1;i<=100000;i++) dp[i]=INF;  //memset
    for (int i=1;i<=20;i++) cout << solve(i) << " ";    //minimum number of coins to make i cents
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}