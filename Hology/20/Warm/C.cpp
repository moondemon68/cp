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

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    LL n,m;
    cin >> n >> m;
    LL ans = 0;
    if (n == m) {
        cout << 3 * (n-1) + 1 << endl;
        return 0;
    }
    else {
        if (n > m) swap(n,m);
        LL g = 1;
        if (__gcd(n,m) != 1) {
            g = __gcd(n,m);
            n /= g;
            m /= g;
            ans += (g-1) * 2;
        }
        // cerr << ans << " ";
        LL cur = 0;
        for (LL i=1;i<=m;i++) {
            LL next = cur + n;
            if (cur/m != next/m) ans += 2 * g; else ans += g;
            cur = next;
            // cerr << ans << " ";
        }
        ans -= g;
    }
    cout << ans << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}