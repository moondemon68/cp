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
            // ans %= MOD;
        }
        a *= a;
        // a %= MOD;
        b >>= 1;
    }
    return ans;
}

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    LL n;
    cin >> n;
    LL a[n+5];
    for (LL i=1;i<=n;i++) cin >> a[i];
    LL c[25];
    memset (c,0,sizeof(c));
    for (LL i=1;i<=n;i++) {
        vector<LL> v;
        while (v.size() < 20) {
            v.pb(a[i]%2);
            a[i] /= 2;
        }
        for (LL j=0;j<20;j++) {
            c[j] += v[j];
        }
    }
    // for (LL i=0;i<20;i++) cout << c[i];
    //     cout << endl;
    LL ans = 0;
    while (true) {
        LL p = 0, q = INT_MAX;
        LL angka = 0;
        for (LL i=19;i>=0;i--) {
            if (c[i] > 0) {
                p = i;
                for (LL j=p;j>=0;j--) {
                    if (c[j] > 0) {
                        q = min(q, c[j]);
                        angka += fpow(2, j);
                    }
                }
                ans += (angka * q) * (angka);
                for (LL j=p;j>=0;j--) {
                    if (c[j] > 0) {
                        c[j] -= q;
                    }
                }
                break;
            }
        }
        // for (LL i=0;i<20;i++) cout << c[i];
        // cout << endl;
        if (p == 0) break;
    }
    cout << ans << endl;

    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
// 01010101010101010101
// 10101010101010101010