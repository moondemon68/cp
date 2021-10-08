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

LL a[200005];
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
        for (LL i=1;i<=n;i++) cin >> a[i];
        LL ans = 0;
        for (LL i=1;i<n;i++) {
            ans += abs(a[i] - a[i+1]);
        }
        LL neg = 0;
        for (int i=2;i<n;i++) {
            if (a[i] > a[i-1] && a[i] > a[i+1]) neg = max(neg, 2 * min(abs(a[i-1] - a[i]), abs(a[i+1] - a[i])));
            if (a[i] < a[i-1] && a[i] < a[i+1]) neg = max(neg, 2 * min(abs(a[i-1] - a[i]), abs(a[i+1] - a[i])));
        }
        neg = max(neg, abs(a[1] - a[2]));
        neg = max(neg, abs(a[n] - a[n-1]));
        // cout << neg << endl;
        cout << ans - neg << '\n';
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
// 18 mins