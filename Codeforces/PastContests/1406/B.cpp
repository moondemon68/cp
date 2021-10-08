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
        bool adanol = 0;
        for (LL i=1;i<=n;i++) {
            cin >> a[i];
            if (a[i] == 0) adanol = 1;
        }
        sort (a+1,a+n+1);
        LL ans = -1000000000000000000;
        ans = max(ans, a[1] * a[2] * a[3] * a[4] * a[5]);
        ans = max(ans, a[1] * a[2] * a[3] * a[4] * a[n]);
        ans = max(ans, a[1] * a[2] * a[3] * a[n-1] * a[n]);
        ans = max(ans, a[1] * a[2] * a[n-2] * a[n-1] * a[n]);
        ans = max(ans, a[1] * a[n-3] * a[n-2] * a[n-1] * a[n]);
        ans = max(ans, a[n-4] * a[n-3] * a[n-2] * a[n-1] * a[n]);
        if (adanol) ans = max(ans, 0LL);
        cout << ans << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}