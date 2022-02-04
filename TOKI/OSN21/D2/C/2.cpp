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

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    LL n;
    cin >> n;
    for (LL i = 1; i <= n; i++) cin >> a[i];
    for (LL i = 1; i <= n; i++) b[i] = a[i];
    reverse(b + 1, b + n + 1);
    LL q;
    cin >> q;
    while (q--) {
        LL l, r;
        cin >> l >> r;
        LL ans = 0;
        if (l + 1 == r) {
            if (a[l] < a[r]) cout << 4 * (a[r] - a[l]) << endl;
            else if (a[l] == a[r]) cout << 2 << endl;
            else cout << a[l] - a[r] << endl;
        } else {
            cout << -1 << endl;
        }
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