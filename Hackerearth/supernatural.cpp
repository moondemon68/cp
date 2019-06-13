#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define LL long long
using namespace std;

LL dp[205][305],n,k;
LL solve(int rem,int x) {
    if (rem==0) return 1;
    if (x==0||rem<0||rem<k||x<k) return 0;
    if (dp[rem][x]!=-1) return dp[rem][x];
    return dp[rem][x]=solve(rem-x,x)+solve(rem,x-1); 
}

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc;
    cin >> tc;
    while (tc--) {
        cin >> n >> k;
        memset (dp,-1,sizeof(dp));
        cout << solve(n,n) << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}