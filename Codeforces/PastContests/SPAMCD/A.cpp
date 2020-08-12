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
        LL ans = 0;
        LL cur = 0;
        cur = a[1];
        for (int i=2;i<=n;i++) {
            cur = max(cur, a[i]);
            if (a[i] < cur) {
                ans = max(ans, cur-a[i]);
            }
            cur = max(cur, a[i]);
            // cout << cur << " ";
        }
        // cout << ans << endl;
        if (ans == 0) cout << ans << endl;
        else if (ans == 1) cout << 1 << endl;
        else {
            LL p = -1, x = 1, y = 1;
            for (int i=1;i<=40;i++) {
                x *= 2;
                y += x;
                p = i+1;
                if (y >= ans) break;
            }
            cout << p << endl;
        }
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
/*
4
25
8 7 6 5 4 3 2 1 0 -1 -2 -3 -4 -5 -6 -7 -8 -9 -10 -11 -12 -13 -14 -15 -16
4
1 7 6 5
5
1 2 3 4 5
2
0 -4
*/