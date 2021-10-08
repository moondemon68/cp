#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pb push_back
#define sz(a) (int)(a).size()
#define mp(a, b) make_pair((a), (b))
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;

const ll MOD = 1e9 + 7;
const ll INF = 1e18;
const ll IINF = INT_MAX;

ll sqr(ll x) {
    x %= MOD;
    return (x * x) % MOD;
}

ll sum(ll n) {
    if (n == 0) return 0;
    if (n & 1) {
        return (sqr((n + 1) / 2) + sum(n / 2)) % MOD;
    } else {
        return (sqr(n / 2) + sum(n / 2)) % MOD;
    }
}

ll fpow(ll a, ll b) {
    if (b == 0) return 1;
    if (b == 1) return a % MOD;
    ll ret = fpow(a, b / 2);
    ret = (ret * ret) % MOD;
    if (b & 1) {
        ret = (ret * a) % MOD;
    }
    return ret;
}

void solve() {
    int x;
    cin >> x;
    int ans = -1;
    // for (int i = 0; i <= 62; i++) {
    //     cout << i << ' ' << (1ll << i) << ' ' << sum(1ll << i) << '\n';
    //     // if (sum(1ll << i) == x) {
    //     //     ans = i;
    //     //     break;
    //     // }
    // }
    ll modinv = fpow(4, MOD - 2);
    cout << modinv << endl;
    for (int i = 0; i <= 1e5; i++) {
        ll val = (fpow(4, i) + 2) % MOD;
        val = (val * modinv) % MOD;
        // cout << val << '\n';
        if (val == x) {
            ans = i;
            break;
        }
        
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tc;
    cin >> tc;
    while (tc--) {
        solve();
    }
    return 0;
}