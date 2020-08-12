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
    LL tc;
    cin >> tc;
    while (tc--) {
        LL n,k;
        cin >> n >> k;
        LL l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        if (l1 > l2) {
            swap(l1, l2);
            swap(r1, r2);
        }
        // fix l1 <= l2

        LL now = (max(0LL, min(r1, r2)-l2));
        k -= now * n;
        if (k <= 0) {
            cout << 0 << endl;
            continue;
        }

        LL ans = 0;
        if (r1 >= l2) {
            LL c1 = max(r1,r2) - min(l1, l2) - now;
            // cout << c1 << endl;
            LL stock1 = c1*n;
            if (stock1 >= k) {
                ans = k;
            } else {
                ans = (k-stock1) * 2 + stock1;
            }
        } else {
            LL costnyambung = l2-r1;
            LL stock = max(r1,r2) - min(l1, l2);
            // k pasti belum berkurang
            // cari berapa yg harus disambung
            ans = INT_MAX;
            for (LL i=1;i<=n;i++) {
                LL x = costnyambung * i;
                LL stock1 = stock * i;
                if (stock1 >= k) {
                    x += k;
                } else {
                    x += (k-stock1) * 2 + stock1;
                }
                ans = min(ans, x);
            }
        }
        cout << ans << endl;

    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}