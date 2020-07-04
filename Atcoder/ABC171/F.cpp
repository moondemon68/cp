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

LL fac[2000005], inv[2000005];

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

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    LL k;
    string s;
    cin >> k >> s;
    LL n = s.size();
    precompute(2000000);

    LL ans = 0;
    for (int i=0;i<=k;i++) {
        LL tmp = 1;
        tmp *= fpow(26, i);
        tmp %= MOD;
        tmp *= fpow(25, k-i);
        tmp %= MOD;
        tmp *= c(n-1+k-i, n-1);
        tmp %= MOD;
        ans += tmp;
        ans %= MOD;
    }
    cout << ans << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}