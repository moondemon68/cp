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

const LL MAXN = 200000;
LL a[MAXN + 5];
LL b[MAXN + 5];
LL ans[MAXN + 5];

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    LL n;
    cin >> n;
    for (LL i = 1; i <= n; i++) cin >> a[i];
    ans[1] = 0;
    LL cur = a[i], curans = 0;
    for (int i = 2; i <= n; i++) {
        if (a[i] > cur) {
            ans[i] = curans + 4 * (a[i] - cur);
        } else if (a[i] < cur) {
            ans[i] = curans + cur - a[i];
        } else {
            ans[i] = curans;
        }
    }
    LL q;
    cin >> q;
    while (q--) {
        LL l, r;
        cin >> l >> r;
        cout << ans[r] << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
/*
6
9 1 8 1 10 1
2
1 6
1 4

19
10

8
1 9 3 3 5 4 8 2
4
1 8
3 6
6 4
7 2

47
9
6
12

4
1 4 1 1
3
1 2
2 3
3 4

12
3
2
*/