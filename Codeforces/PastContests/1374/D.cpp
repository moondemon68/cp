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
        LL a[n+5];
        for (LL i=1;i<=n;i++) {
            cin >> a[i];
            a[i] %= k;
            a[i] = k-a[i];
        }
        sort (a+1,a+n+1);
        map<LL,LL> m;
        for (LL i=1;i<=n;i++) {
            if (a[i] == k) continue;
            m[a[i]]++;
        }
        LL pass = 0;
        for (auto x : m) {
            pass = max(pass, x.se);
        }
        // cout << pass-1 << " " << (pass-1) * k << " ";
        LL ans = (pass-1) * k;
        LL maxi = 0;
        for (auto x : m) {
            if (x.se == pass) {
                maxi = max(maxi, x.fi);
            }
        }
        // cout << maxi << endl;
        ans += maxi + 1;
        if (ans < 0) ans = 0;
        cout << ans << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}