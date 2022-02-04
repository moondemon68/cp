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
        int n, m, c;
        cin >> n >> m >> c;
        char a[n+5][m+5];
        for (int i=1;i<=n;i++) {
            string s;
            cin >> s;
            for (int j=1;j<=m;j++) {
                a[i][j] = s[j-1];
            }
        }
        c++;    // buat warna kosong

        int dp[m+5][c*c];
        memset(dp,0,sizeof(dp));
        for (int i=0;i<c*c;i++) {
            if (i % c == 0) {
                dp[1][i] = 1;
            } else if (i/c == 0) {
                dp[1][i] = 1;
            } else {
                dp[1][i] = 1;
            }
        }
        for (int i=2;i<=m;i++) {
            for (int j=0;j<c*c;j++) {
                for (int k=0;k<c*c;k++) {
                    if (a[1][i-1] == '#' && (j % c > 0)) continue;
                    if (a[2][i-1] == '#' && (j / c > 0)) continue;
                    if (a[1][i] == '#' && (k % c > 0)) continue;
                    if (a[2][i] == '#' && (k / c > 0)) continue;
                    if (a[1][i-1] == '.' && (j % c == 0)) continue;
                    if (a[2][i-1] == '.' && (j / c == 0)) continue;
                    if (a[1][i] == '.' && (k % c == 0)) continue;
                    if (a[2][i] == '.' && (k / c == 0)) continue;
                    vector<int> v;
                    if (a[1][i-1] == '.') v.pb(j%c);
                    if (a[2][i-1] == '.') v.pb(j/c);
                    if (a[1][i] == '.') v.pb(k%c);
                    if (a[2][i] == '.') v.pb(k/c);
                    sort(v.begin(), v.end());
                    if (v.size() >= 3 && v[0] == v[1] && v[1] == v[2]) continue;
                    if (v.size() >= 4 && v[1] == v[2] && v[2] == v[3]) continue;
                    dp[i][k] += dp[i-1][j];
                    dp[i][k] %= MOD;
                }
            }
        }
        int ans = 0;
        for (int i=0;i<c*c;i++) {
            if (i % c > 0 && a[1][m] == '#') continue;
            if (i / c > 0 && a[2][m] == '#') continue;
            ans += dp[m][i];
            ans %= MOD;
        }
        cout << ans << endl;
        // for (int i=1;i<=m;i++) {
        //     for (int j=0;j<c*c;j++) {
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << endl;
        // }
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}