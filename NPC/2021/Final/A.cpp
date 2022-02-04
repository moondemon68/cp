// ez
#include <bits/stdc++.h>
#define pb push_back

using namespace std;

int dp[20][500];
vector<int> v;

int solve(int n, int k) {
    if (k > v.size()) return 1e9;
    if (n < 0) return 1e9;
    if (n == 0) return 0;
    if (dp[n][k] != 1e9) return dp[n][k];
    int ans = 1e9;
    for (int i=k;i<v.size();i++) {
        if ((n - v[i]) >= 0) {
            ans = min(ans, solve(n - v[i], i+1) + 1);
        }
    }
    cout << n << " " << k << " " << ans;
    return dp[n][k] = ans;
}

int main () {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        v.clear();
        for (int i=1;i*i<=n;i++) {
            if (n % i == 0) {
                v.pb(i);
                if (i * i != n) {
                    v.pb(n/i);
                }
            }
        }
        sort(v.begin(), v.end());
        for (int i=0;i<=13;i++) {
            for (int j=0;j<v.size();j++) {
                dp[i][j] = 1e9;
            }
        }
        int ans = solve(n, 0);
        for (int i=0;i<=13;i++) {
            for (int j=0;j<=13;j++) {
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}