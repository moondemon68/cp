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

LL fpow(LL a, LL b) {
    LL ans = 1;
    while (b) {
        if (b & 1) {
            ans *= a;
            ans %= MOD;
        }
        a *= a;
        a %= MOD;
        b >>= 1;
    }
    return ans;
}

const int MAXN = 2000000;
LL fac[MAXN+5], inv[MAXN+5];

// don't forget to call this function
void precompute(LL x) {
    fac[0] = 1;
    inv[0] = 1;
    for (LL i=1;i<=x;i++) {
        fac[i] = fac[i-1] * i;
        fac[i] %= MOD;
        inv[i] = fpow(fac[i], MOD-2);
    }
}

LL c(LL n, LL k) {
    if (n < k) return 0;
    LL ret = fac[n];
    ret *= inv[k];
    ret %= MOD;
    ret *= inv[n-k];
    ret %= MOD;
    return ret;
}

LL d[500005];

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // int cnt = 0;
    // int p = 7;
    // for (int i=1;i<=p;i++) {
    //     for (int j=1;j<=p;j++) {
    //         for (int k=1;k<=p;k++) {
    //             if (i == j || j == k || i == k) continue;
    //             if (i == 1 || j == 2 || k == 3) continue;
    //             cnt++;
    //         }
    //     }
    // }
    // cout << cnt << endl;
    precompute(MAXN);
    // LL anss = 0, nn = 5, t = 2;
    // for (int i=0;i<=t;i++) {
    //     if (i % 2 == 0) {
    //         anss += ((c(t, i) * fac[nn-i])%MOD * inv[nn-t])%MOD;
    //         anss %= MOD;
    //     } else {
    //         anss -= ((c(t, i) * fac[nn-i])%MOD * inv[nn-t])%MOD;
    //         anss %= MOD;
    //     }
    // }
    // cout << anss;

    // return 0;

    int n,m;
    cin >> n >> m;

    d[0] = 1;
    d[1] = 0;
    for (int i=2;i<=n;i++) {
        d[i] = d[i-1] * i;
        if (i % 2 == 0) d[i]++; else d[i]--;
        d[i] %= MOD;
    }

    LL ans = c(m,n) * fac[n];
    ans %= MOD;
    // ans *= c(m-1,n);
    // ans %= MOD;

    LL magic = 0;
    for (int i=0;i<=n;i++) {
        if (i % 2 == 0) {
            magic += ((c(n, i) * fac[m-i])%MOD * inv[m-n])%MOD;
            magic %= MOD;
        } else {
            magic -= ((c(n, i) * fac[m-i])%MOD * inv[m-n])%MOD;
            magic %= MOD;
            if (magic < 0) magic += MOD;
        }
    }
    ans *= magic;
    ans %= MOD;
    // ans *= d[n];
    // ans %= MOD;
    cout << ans << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}