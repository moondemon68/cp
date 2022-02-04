#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define INF 1234567890
#define pii pair<LL,LL>
#define LL long long
using namespace std;

LL n, m;
char g[50][5];
LL good[50][1 << 5];
LL szg[50];
LL block[50];
LL dp[50][1 << 15];
LL dp2[1 << 15];

LL spread(LL mask) {
    if (dp2[mask] != -1) return dp2[mask];
    LL nmask = 0;
    for (LL i = 0; i < m; i++) {
        if (mask & 1 << 3 * i && i > 0) {
            nmask |= 1 << 3 * i - 3;
        }
        if (mask & 1 << 3 * i + 1) {
            nmask |= 1 << 3 * i + 1;
        }
        if (mask & 1 << 3 * i + 2 && i + 1 < m) {
            nmask |= 1 << 3 * i + 5;
        }
    }
    return dp2[mask] = nmask;
}

LL solve(LL x, LL mask) {
    if (x == n) return 1;
    mask &= ~block[x];
    if (dp[x][mask] != -1) return dp[x][mask];
    LL ret = 0;
    for (LL i = 0; i < szg[x]; i++) {
        if (!(good[x][i] & mask)) {
            ret += solve(x + 1, spread(good[x][i] | mask));
            ret %= MOD;
        }
    }
    return dp[x][mask] = ret;
}

LL solve() {
    for (LL i=0;i<n;i++) {
        block[i] = 0;
        LL cmask = 0;
        for (LL j=0;j<m;j++) {
            if (g[i][j] == '#') {
                cmask |= 1 << j;
                block[i] |= 7 << 3 * j;
            }
        }
        szg[i] = 0;
        for (LL j=0;j<(1<<m);j++) {
            if ((j & cmask) == 0) {
                bool y = 1;
                for (LL k=0;k<m;k++) {
                    if (j & 1 << k) {
                        for (LL l=k+1;l<m && g[i][l] != '#'; l++) {
                            if (j & 1 << l) {
                                y = 0;
                            }
                        }
                    }
                }
                if (!y) continue;
                LL sp = 0;
                for (LL k=0;k<m;k++) {
                    if (j & 1 << k) {
                        sp |= 7 << 3 * k;
                    }
                }
                good[i][szg[i]] = sp;
                szg[i]++;
            }
        }
    }
    memset(dp, -1, sizeof(dp));
    memset(dp2, -1, sizeof(dp2));
    return solve(0, 0);
}

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    LL tc;
    cin >> tc;
    while (tc--) {
        cin >> n >> m;
        for (LL i=0;i<n;i++) {
            string s;
            cin >> s;
            for (LL j=0;j<m;j++) {
                g[i][j] = s[j];
            }
        }
        LL ret = solve();
        ret = (ret - 1 + MOD) % MOD;
        cout << ret << '\n';
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}