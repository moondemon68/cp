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

const LL MAXN = 1e5;

LL a[MAXN * 2 + 5];

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
        for (LL i=1;i<=2*n;i++) cin >> a[i];
        sort(a+1,a+n+n+1);
        bool y = 1;
        for (LL i=1;i<=2*n;i+=2) {
            if (a[i] != a[i+1] || a[i] % 2 == 1) y = 0;
        }
        vector<LL> v;
        for (LL i=1;i<2*n-2;i+=2) {
            v.pb(a[i+2] - a[i]);
        }
        for (LL i=0;i<v.size();i++) {
            if (v[i] % ((i+1) * 2) != 0) y = 0;
            else v[i] = v[i] / ((i+1) * 2);
        }
        LL p = 1, tot = 1;
        for (auto x : v) {
            p += x;
            tot += p;
            if (x == 0) y = 0;
        }
        // cout << tot << endl;
        if ((a[1]/2 - tot) % n != 0 || a[1]/2 < tot) y = 0;
        // for (auto x : v) cout << x << " ";
        if (!y) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }

    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}