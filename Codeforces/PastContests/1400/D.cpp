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

const LL MAXN = 5000;
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
    precompute(3005);
    LL tc;
    cin >> tc;
    while (tc--) {
        LL n;
        cin >> n;
        LL a[n+5];
        for (LL i=1;i<=n;i++) cin >> a[i];
        vector<LL> cnt[n+5];
        for (LL i=1;i<=n;i++) {
            cnt[a[i]].pb(i);
        }
        LL ans = 0;
        for (LL i=1;i<=n;i++) {
            for (LL j=1;j<=n;j++) {
                if (cnt[i].empty() || cnt[j].empty()) continue;
                if (i == j) {
                    if (cnt[i].size() >= 4) ans += c(cnt[i].size(), 4);
                } else {
                    vector<pii> v;
                    for (int k=0;k<cnt[i].size();k++) {
                        v.pb({cnt[i][k], 0});
                    }
                    for (int k=0;k<cnt[j].size();k++) {
                        v.pb({cnt[j][k], 1});
                    }
                    sort (v.begin(), v.end());
                    vector<int> p;
                    for (int k=0;k<v.size();k++) {
                        
                    }
                }
            }
        }
        cout << ans << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}