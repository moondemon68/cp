#include <bits/stdc++.h>

using namespace std;

const int N = 2e3 + 5;
const int M = 1e9 + 7;
int n, e, k;
bool inv[N][N];
int dp[N];

int mmod(int a, int b) {
    return ((a + b) % M + M) % M;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> e >> k;
    for (int i = 1; i <= k; i++) {
        int u, v;
        cin >> u >> v;
        inv[u][v] = 1;
    }

    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        dp[i] = 0;
        for (int j = 0; j <= e; j++) {
            if (j == 0 && !inv[i][i]) {
                dp[i] = mmod(dp[i], dp[i - 1]);
            } else if (j == 1 && i > 1 && !inv[i][i - 1] && !inv[i - 1][i]) {
                dp[i] = mmod(dp[i], dp[i - 2]);
            } else if (j == 2 && i > 2) {
                if (!inv[i][i - 2] && !inv[i - 2][i] && !inv[i - 1][i - 1]) {
                    dp[i] = mmod(dp[i], dp[i - 3]);
                }
                if (i > 3 && !inv[i][i - 2] && !inv[i - 2][i] && !inv[i - 3][i - 1] && !inv[i - 1][i - 3]) {
                    dp[i] = mmod(dp[i], dp[i - 4]);
                }
                if (!inv[i][i - 2] && !inv[i - 1][i] && !inv[i - 2][i - 1]) {
                    dp[i] = mmod(dp[i], dp[i - 3]);
                }
                if (!inv[i - 2][i] && !inv[i][i - 1] && !inv[i - 1][i - 2]) {
                    dp[i] = mmod(dp[i], dp[i - 3]);
                }
                // cari kasus lagi :(
            } else if (j == 3 && i > 3) {
                if (!inv[i][i - 3] && !inv[i - 3][i]) {
                    if (!inv[i - 1][i - 1] && !inv[i - 2][i - 2]) {
                        mmod(dp[i], dp[i - 4]);
                    }
                    if (!inv[i - 1][i - 2] && !inv[i - 2][i - 1]) {
                        mmod(dp[i], dp[i - 4]);
                    }
                }
                // cari kasus lagi :(
            } else if (j == 4 && i > 4) {
                // cari kasus lagi :(
            }
        }
        dp[i] %= M;
    }
    cout << dp[n] << endl;
    return 0;
}