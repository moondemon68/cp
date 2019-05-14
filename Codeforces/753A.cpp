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
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    int dp[1005];
    memset (dp,0,sizeof(dp));
    dp[1]=1;
    int ans=0;
    for (int i=2;i<=1000;i++) dp[i]=dp[i-1]+i;
    for (int i=1;i<=1000;i++) {
        if (n<dp[i]) {
            ans=i-1;
            break;
        }
    }
    cout << ans << endl;
    for (int i=1;i<ans;i++) cout << i << " ";
    cout << n-dp[ans-1] << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}