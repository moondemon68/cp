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
    LL n;
    cin >> n;
    LL a[2*n+5];
    for (LL i=1;i<=n;i++) {
        cin >> a[i];
        a[i+n] = a[i];
    }
    if (n <= 2) {
        cout << -1 << endl;
        return 0;
    }
    LL tot = 0;
    for (LL i=1;i<=n;i++) tot += a[i];
    vector<LL> v;
    for (LL i=1;i*i<=tot;i++) {
        if (tot%i == 0) {
            v.pb(i);
            v.pb(tot/i);
        }
    }
    LL ans = 123456789;
    for (auto target : v) {
        if (tot/target < 3) continue;
        bool y = 1;
        for (LL i=1;i<=n;i++) {
            if (a[i] > target) {
                y = 0;
                break;
            }
        }
        if (!y) continue;
        bool dapet = 0;
        for (LL j=1;j<=n;j++) {
            LL cur = 0, cnt = 0;
            bool bisa = 1;
            for (LL i=j;i<=j+n-1;i++) {
                cur += a[i];
                if (cur == target) {
                    cnt++;
                    cur = 0;
                } else if (cur > target) {
                    bisa = 0;
                    break;
                }
            }
            if (bisa) dapet = 1;
            if (dapet) break;
        }
        if (!dapet) continue;
        ans = min(ans, n-tot/target);
    }
    if (ans == 123456789) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}