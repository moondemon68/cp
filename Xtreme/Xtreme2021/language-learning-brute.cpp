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
    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        string a[n+5];
        for (int i=1;i<=n;i++) cin >> a[i];
        set<string> s;
        int dp[n+5];
        memset(dp,0,sizeof(dp));
        for (int i=1;i<=n;i++) {
            if (s.find(a[i]) == s.end()) {
                s.insert(a[i]);
                dp[i]++;    // dia sendiri
            }
            set<string> s2;
            for (int j=i+k+1;j<=n;j++) {
                if (s2.find(a[j]) == s2.end()) {
                    s2.insert(a[j]);
                    dp[j] += dp[i];
                }
            }
        }
        for (int i=1;i<=n;i++) cout << dp[i] << " ";
        cout << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}