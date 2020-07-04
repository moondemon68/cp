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
        deque<LL> p,q;
        LL tot = 0;
        for (LL i=1;i<=n;i++) {
            if (i%2 == 1) {
                p.pb(a[i]);
                tot += a[i];
            }
            else q.pb(a[i]);
        }
        LL cnt = 0, ans = 0;
        for (LL i=0;i<p.size();i++) {
            if (i >= q.size()) continue;
            cnt += (q[i]-p[i]);
            if (cnt < 0) cnt = 0;
            ans = max(ans, cnt);
        }

        cnt = 0;
        q.push_front(0);
        for (LL i=1;i<p.size();i++) {
            if (i >= q.size()) continue;
            cnt += (q[i]-p[i]);
            if (cnt < 0) cnt = 0;
            ans = max(ans, cnt);
        }
        // cout << ans << " " << tot << endl;
        cout << ans+tot << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}