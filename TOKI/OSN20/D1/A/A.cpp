#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define INF 1234567890
#define pii pair<int,int>
#define LL long long
using namespace std;

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    for (int tc=1;tc<=10;tc++) {
        if (tc == 1) continue;
        if (tc == 3) continue;
        string num = "";
        num += ('0' + tc);
        if (tc == 10) num = "10";
        ifstream cin("inputs/pertahanan_" + num + ".in");
        ofstream cout("pertahanan_" + num + ".out");

        int n,m,k;
        cin >> n >> m >> k;
        LL a[k+5];
        a[0] = 0;
        for (int i=1;i<=k;i++) {
            cin >> a[i];
        }

        vector<pair<pii,pii>> ans;
        int fib[28] = {1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597, 2584, 4181, 6765, 10946, 17711, 28657, 46368, 75025, 121393, 196418, 317811};
        if (tc == 6) {
            // ans.pb({{0, 1}, {0, 1}});
            // ans.pb({{0, 1}, {1, 2}});
            // ans.pb({{1, 3}, {0, 2}});
            // ans.pb({{0, 3}, {2, 5}});
            // for (int i = 4;i<k;i++) {
            //     if (i % 2 == 0) {
            //         ans.pb({{fib[i-1], fib[i+1]}, {0, fib[i]}});
            //     } else {
            //         ans.pb({{0, fib[i]}, {fib[i-1], fib[i+1]}});
            //     }
            // }

            LL cur = 0, cury = 0, d = 1;
            for (int i=1;i<=k;i++) {
                while (cur + a[i]/d > m && d <= n && a[i] % d != 0) d++;
                if (a[i]/d == 0 || cury + d > n) {
                    ans.pb({{-1, -1}, {-1, -1}});
                } else if (cur + a[i]/d <= m) {
                    ans.pb({{cury, cury + d}, {cur, cur + a[i]/d}});
                    cur += a[i]/d;
                } else {
                    ans.pb({{cury, cury + d}, {cur, m}});
                }
                if (cur + a[i]/d >= m) {
                    cur = 0;
                    cury += d;
                }
            }
            cerr << m-cur << endl;
            
            // LL curr = cur;
            // for (int i=0;i<k;i++) {
            //     if (a[i+1] % 2 == 1 && curr + a[i+1] <= m) {
            //         ans[i].fi.fi = 0;
            //         ans[i].fi.se = 1;
            //         ans[i].se.fi = curr;
            //         ans[i].se.se = curr + a[i+1];
            //         curr += a[i+1];
            //     }
            // }
            // curr = cur;
            // for (int i=0;i<k;i++) {
            //     if (a[i+1] % 2 == 1 && curr + a[i+1] <= m && ans[i].fi.fi == -1) {
            //         ans[i].fi.fi = 1;
            //         ans[i].fi.se = 2;
            //         ans[i].se.fi = curr;
            //         ans[i].se.se = curr + a[i+1];
            //         curr += a[i+1];
            //     }
            // }
            // ans[k-1] = {{1, 2}, {curr, m}};
        } else continue;

        for (int i=0;i<ans.size();i++) {
            cout << ans[i].fi.fi << " " << ans[i].fi.se << " " << ans[i].se.fi << " " << ans[i].se.se << endl;
        }

        // for (int i=1;i<=k;i++) {
        //     if (a[i] <= m && i <= n) cout << i-1 << " " << i << " " << 0 << " " << a[i] << endl;
        //     else cout << -1 << " " << -1 << " " << -1 << " " << -1 << endl;
        // }
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}