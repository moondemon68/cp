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
        LL a[n+5], b[n+5];
        for (LL i=1;i<=n;i++) cin >> a[i];
        for (LL i=1;i<=n;i++) cin >> b[i];
        LL ma = INT_MAX, mb = INT_MAX;
        for (LL i=1;i<=n;i++) ma = min(ma, a[i]);
        for (LL i=1;i<=n;i++) mb = min(mb, b[i]);
        LL ans = 0;
        for (LL i=1;i<=n;i++) {
            LL x = a[i]-ma, y = b[i]-mb;
            ans += x+y-min(x,y);
        }
        cout << ans << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}