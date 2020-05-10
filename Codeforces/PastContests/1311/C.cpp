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
    int tc;
    cin >> tc;
    while (tc--) {
        int n,m;
        cin >> n >> m;
        string s;
        cin >> s;
        int ans[30];
        memset (ans,0,sizeof(ans));
        int dp[n+5][30];
        memset (dp,0,sizeof(dp));
        for (int i=1;i<=n;i++) {
            dp[i][s[i-1]-'a'] = 1;
        }
        for (int i=1;i<=n;i++) {
            for (int j=0;j<26;j++) {
                dp[i][j] += dp[i-1][j];
            }
        }
        for (int i=1;i<=m;i++) {
            int x;
            cin >> x;
            for (int j=0;j<26;j++) {
                ans[j] += dp[x][j];
            }
            // for (int i=0;i<26;i++) cout << ans[i] << " ";
            // cout << endl;
        }
        for (int i=0;i<n;i++) {
            ans[s[i]-'a']++;
        }
        for (int i=0;i<26;i++) cout << ans[i] << " ";
        cout << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}