#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 998244353
#define INF 1234567890
#define pii pair<LL,LL>
#define LL long long
using namespace std;

const LL MAXN = 2000000;
LL fac[MAXN+5], inv[MAXN+5];
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
    precompute(n);
    pii a[n+5];
    for (LL i=1;i<=n;i++) cin >> a[i].fi >> a[i].se;
    LL ans = fac[n];
    set<LL> s;
    map<LL,LL> cnt;
    for (LL i=1;i<=n;i++) {
        s.insert(a[i].fi);
        cnt[a[i].fi]++;
    }
    set<LL> sb;
    map<LL,LL> cntb;
    for (LL i=1;i<=n;i++) {
        sb.insert(a[i].se);
        cntb[a[i].se]++;
    }
    // cerr << ans << " ";
    LL tmp = 1;
    for (auto x : s) {
        tmp *= fac[cnt[x]];
        tmp %= MOD;
    }
    ans -= tmp;
    ans += MOD;
    ans %= MOD;
    // cerr << tmp << " ";
    tmp = 1;
    for (auto x : sb) {
        tmp *= fac[cntb[x]];
        tmp %= MOD;
    }
    // cerr << tmp << " ";
    ans -= tmp;
    ans += MOD;
    ans %= MOD;
    sort (a+1,a+n+1);
    bool y = 1;
    for (LL i=1;i<n;i++) {
        if (a[i+1].se < a[i].se) y = 0;
    }
    if (!y) {
        cout << ans << endl;
        return 0;
    }
    tmp = 1;
    for (LL i=1;i<=n;i++) {
        set<LL> s2;
        map<LL,LL> cnt2;
        LL k = i;
        for (LL j=i+1;j<=n;j++) {
            if (a[i].fi != a[j].fi) break;
            cnt2[a[j].se]++;
            s2.insert(a[j].se);
            k = j;
        }
        s2.insert(a[i].se);
        cnt2[a[i].se]++;
        for (auto x : s2) {
            tmp *= fac[cnt2[x]];
            tmp %= MOD;
        }
        i = k;
    }
    // cerr << tmp << " ";
    ans += tmp;
    ans %= MOD;
    cout << ans << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}