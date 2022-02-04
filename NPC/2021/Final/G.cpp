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

const LL MAXN = 2000000;
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
int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    LL n;
    cin >> n;
    LL cnt[n+5];
    memset(cnt,0,sizeof(cnt));
    for (LL i=1;i<=n;i++) {
        LL x;
        cin >> x;
        cnt[x]++;
    }
    LL g = 0;
    LL cnt2[n+5];
    memset(cnt2,0,sizeof(cnt2));
    for (LL i=1;i<=n;i++) {
        cnt2[cnt[i]]++;
    }
    // for (LL i=1;i<=n;i++) {
    //     cout << cnt2[i] << " ";
    // }
    precompute(1000000);
    LL ans = 1;
    for (LL i=1;i<=n;i++) {
        if (cnt2[i] == 0) continue;
        LL tmp = 0;
        for (LL j=0;j<=cnt2[i];j+=2) {
            tmp += c(cnt2[i], j);
            tmp %= MOD;
        }
        // cout << cnt2[i] << " " << tmp << endl;
        ans *= tmp;
        ans %= MOD;
    }
    cout << ans << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}