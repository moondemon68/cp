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

const LL MAXN = 100000;
pii a[MAXN + 5];
int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    LL tc;
    cin >> tc;
    while (tc--) {
        LL A, B, n;
        cin >> A >> B >> n;
        for (LL i=1;i<=n;i++) cin >> a[i].fi;
        for (LL i=1;i<=n;i++) cin >> a[i].se;
        sort(a+1, a+n+1);
        for (LL i=1;i<=n;i++) {
            LL req = (a[i].se + A - 1) / A;
            if (i == n) {
                B -= a[i].fi * (req - 1);
                if (B > 0) {
                    cout << "YES" << endl;
                } else {
                    cout << "NO" << endl;
                }
            } else {
                B -= a[i].fi * req;
            }
        }
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}