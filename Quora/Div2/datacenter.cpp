#include <bits/stdc++.h>
#define x first.first
#define y first.second
#define p second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define INF 1234567890
#define pii pair<LL,LL>
#define LL long long
using namespace std;

const LL MAXN = 500000;
pair<pii, LL> a[MAXN + 5];

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    LL n;
    cin >> n;
    bool same = 1;
    for (LL i=1;i<=n;i++) {
        cin >> a[i].x >> a[i].y;
        a[i].p = i;
        if (a[i].x != a[i].y) same = 0;
    }
    LL ans = 9223372036854775807, ansp = 1000000;
    if (n <= 1000) {
        for (LL i=1;i<=n;i++) {
            LL cur = 0;
            for (LL j=1;j<=n;j++) {
                cur += max(abs(a[i].x-a[j].x), abs(a[i].y-a[j].y));
            }
            if (cur < ans) {
                ans = cur;
                ansp = a[i].p;
            }
        }
        cout << ansp << endl;
    } else if (same) {
        sort(a+1,a+n+1);
        // for (int i=1;i<=n;i++) {
        //     cout << a[i].x << " " << a[i].y << " " << a[i].p << endl;
        // }
        for (int i=1;i<=n;i++) {
            if (n % 2 == 1) {
                if (a[i].x == a[(n+1)/2].x) {
                    ansp = min(ansp, a[i].p);
                }
            } else {
                if (a[i].x == a[n/2].x || a[i].x == a[n/2+1].x) {
                    ansp = min(ansp, a[i].p);
                }
            }
        }
        cout << ansp << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}