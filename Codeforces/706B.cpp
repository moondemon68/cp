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
    int a[n+5];
    for (int i=1;i<=n;i++) cin >> a[i];
    int dp[100005];
    memset (dp,0,sizeof(dp));
    for (int i=1;i<=n;i++) {
        dp[a[i]]++;    
    }
    for (int i=1;i<=100000;i++) {
        dp[i]+=dp[i-1];
    }
    int q;
    cin >> q;
    for (int i=1;i<=q;i++) {
        int x;
        cin >> x;
        if (x>100000) cout << n << endl;
        else cout << dp[x] << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}