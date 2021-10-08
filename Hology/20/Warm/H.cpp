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

map<LL, pii> cnt;
int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    LL n;
    cin >> n;
    LL a[n+5];
    for (LL i=1;i<=n;i++) cin >> a[i];
    LL b[n+5];
    for (LL i=1;i<=n;i++) cin >> b[i];
    LL ans = 0;
    set<LL> s;
    for (LL i=1;i<=n;i++) {
        s.insert(a[i]);
        cnt[a[i]].fi += b[i];
        cnt[a[i]].se += 1;
    }
    for (auto x : s) {
        if (cnt[x].se > 1) {
            ans += cnt[x].fi;
        }
    }
    for (LL i=1;i<=n;i++) {
        if (cnt[a[i]].se == 1) {
            for (auto x : s) {
                if (cnt[x].se > 1 && (x & a[i]) == a[i]) {
                    ans += b[i];
                    break;
                }
            }
        }
    }
    cout << ans << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}