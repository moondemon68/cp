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
    int a[n+5][m+5];
    memset (a,0,sizeof(a));
    for (int i=1;i<=n;i++) {
        string s;
        cin >> s;
        for (int j=1;j<=m;j++) {
            a[i][j] = s[j-1];
        }
    }

    int cnt[15];
    memset (cnt,0,sizeof(cnt));
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=m;j++){
            cnt[a[i][j]]++;
        }
    }
    int dp[n+5][m+5];
    memset(dp,0,sizeof(dp));
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=m;j++) {
            dp[i][j] = a[i][j];
        }
    }
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=m;j++) {
            dp[i][j] += dp[i-1][j];
        }
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}