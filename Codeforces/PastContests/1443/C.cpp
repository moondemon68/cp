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
        LL n;
        cin >> n;
        LL a[n+5];
        for (LL i=1;i<=n;i++) cin >> a[i];
        LL b[n+5];
        for (LL i=1;i<=n;i++) cin >> b[i];
        LL l = 1, h = 1e9, ans = 1e9;
        while (l <= h) {
            LL m = (l + h) / 2;
            LL cnt = 0;
            for (LL i=1;i<=n;i++) {
                if (a[i] <= m) continue;
                else cnt += b[i];
            }
            if (cnt <= m) {
                ans = m;
                h = m-1;
            } else {
                l = m+1;
            }
        }
        cout << ans << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}