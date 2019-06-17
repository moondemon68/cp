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

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m;
    cin >> n >> m;
    int c[m+5];
    for (int i=1;i<=m;i++) cin >> c[i]; //coins
    int dp[100005],last[100005];
    for (int i=1;i<=100000;i++) dp[i]=INF;  //memset
    dp[0]=0;    //base case
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=m;j++) {
            if (c[j]<=i) {
                if (dp[i-c[j]]+1<dp[i]) {   //recurrence
                    dp[i]=dp[i-c[j]]+1;
                    last[i]=c[j];
                }
            }
        }
    }
    cout << dp[n] << endl;
    while (n>0) {
        cout << last[n] << " ";
        n-=last[n];
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}