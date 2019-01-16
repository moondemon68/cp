#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define LL long long

using namespace std;

int n,k,a[105],dp[100005];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> k;
    for (int i=1;i<=n;i++) cin >> a[i];
    memset (dp,0,sizeof(dp));
    for (int i=1;i<=k;i++) {
        for (int j=1;j<=n;j++) {
            if (a[j]<=i&&dp[i-a[j]]==0) dp[i]=1; 
        }
    }
    //for (int i=1;i<=n;i++) cout << dp[k] << " ";
    if (dp[k]==1) cout << "First" << endl;
    else cout << "Second" << endl;
    return 0;
}
