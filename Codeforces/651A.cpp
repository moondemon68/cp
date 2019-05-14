#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define LL long long
using namespace std;

int dp[105][105];
int solve(int a,int b) {
    if (a<=0||b<=0) return 0;
    else if (dp[a][b]!=-1) return dp[a][b];
    else return dp[a][b]=max(solve(a-2,b+1)+1,solve(a+1,b-2)+1);
}

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m;
    cin >> n >> m;
    memset (dp,-1,sizeof(dp));
    if (n==1&&m==1) {
        cout << 0 << endl;
        return 0;
    }
    cout << solve(n,m) << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}