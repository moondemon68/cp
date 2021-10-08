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
    LL n,t;
    cin >> n >> t;
    LL a[n+5];
    for (LL i=1;i<=n;i++) cin >> a[i];
    LL l = 0, r = 1e18, ans = 1e18;
    while (l <= r) {
        LL m = (l+r) / 2;
        LL cnt = 0;
        for (LL i=1;i<=n;i++) {
            cnt += m/a[i];
            if (cnt > t) break;
        }
        if (cnt >= t) {
            ans = m;
            r = m-1;
        } else {
            l = m+1;
        }
    }
    cout << ans << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}