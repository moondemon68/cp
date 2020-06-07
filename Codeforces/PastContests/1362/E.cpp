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

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    LL tc;
    cin >> tc;
    while (tc--) {
        LL n,p;
        cin >> n >> p;
        LL a[n+5];
        for (LL i=1;i<=n;i++) cin >> a[i];
        sort (a+1,a+n+1);
        reverse(a+1,a+n+1);
        a[n+1] = -1;
        vector<LL> b,c;
        LL cnt = 0;
        for (LL i=1;i<=n;i++) {
            if (a[i] != a[i+1]) {
                b.pb(a[i]);
                c.pb(cnt+1);
                cnt = 0;
            } else {
                cnt++;
            }
        }
        // for (LL i=0;i<b.size();i++) cout << b[i] << " " << c[i] << endl;
        // cout << endl;
        bool fail = 0;
        LL ans = 0;
        for (LL i=0;i<b.size();i++) {
            if (c[i] % 2 == 1) {
                LL need = 1;
                for (LL j=i+1;j<b.size();j++) {
                    if (p > 1) {
                        for (LL k=1;k<=b[j-1]-b[j];k++) {
                            need *= p;
                            if (need > 1e12) {
                                fail = 1;
                                break;
                            }
                        }
                    }
                    if (fail) break;
                    else {
                        if (c[j] >= need) {
                            c[j] -= need;
                            need = 0;
                            c[i] = 0;
                            for (int k=i+1;k<j;k++) c[k] = 0;
                            break;
                        } else {
                            need -= c[j];
                        }
                    }
                }
                if (need > 0) fail = 1;
                if (fail) {
                    // cout << "1->" << p << "^" << b[i] << endl;
                    ans += fpow(p, b[i]);
                    for (LL j=i+1;j<b.size();j++) {
                        // cout << "2->" << " " << c[j] << "x" << p << "^" << b[j] << endl;
                        ans -= (fpow(p, b[j]) * c[j])%MOD;
                        ans += MOD;
                        ans %= MOD;
                    }
                    break;
                }
            } else {
                c[i] = 0;
            }
        }
        cout << ans << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}