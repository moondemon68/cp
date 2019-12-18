#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define LL long long
using namespace std;

int min3(int a,int b,int c) {
    return min(min(a,b),c);
}

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,c;
    cin >> n >> c;
    int dp[n+5][3];  // id, 
    memset (dp,0,sizeof(dp));
    dp[1][0]=0;
    dp[1][1]=0;
    dp[1][2]=0;
    int a[n+5],b[n+5];
    for (int i=1;i<n;i++) cin >> a[i];
    for (int i=1;i<n;i++) cin >> b[i];
    dp[2][0]=a[1];
    dp[2][1]=b[1]+c;
    dp[2][2]=b[1]+c;
    for (int i=3;i<=n;i++) {
        dp[i][0]=min3(dp[i-1][0],dp[i-1][1],dp[i-1][2])+a[i-1];
        dp[i][1]=(dp[i-1][0])+b[i-1]+c;
        dp[i][2]=min(dp[i-1][1],dp[i-1][2])+b[i-1];
    }
    // for (int i=1;i<=n;i++) cout << dp[i][0] << " ";
    // cout << endl;
    // for (int i=1;i<=n;i++) cout << dp[i][1] << " ";
    // cout << endl;
    // for (int i=1;i<=n;i++) cout << dp[i][2] << " ";
    // cout << endl;
    for (int i=1;i<=n;i++) cout << min3(dp[i][0], dp[i][1], dp[i][2]) << " ";
    cout << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}