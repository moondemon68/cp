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
    LL p,n;
    cin >> p >> n;
    map<LL,LL> m;
    set<LL> s;
    for (LL i=1;i<=n;i++) {
        LL x;
        cin >> x;
        m[x]++;
        s.insert(x);
    }
    pii a[n+5];
    LL k = 1;
    for (auto x : s) {
        a[k] = {x, m[x]};
        k++;
    }
    a[0] = {0, 0};
    a[k] = {p+1, 0};
    sort(a+1,a+k+1);
    for (LL i=1;i<=k;i++) {
        a[i].se += a[i-1].se;
    }
    // for (LL i=1;i<=k;i++) {
    //     cout << a[i].fi << " " << a[i].se << endl;
    // }
    LL q;
    cin >> q;
    while (q--) {
        LL x;
        cin >> x;
        LL l = 0, r = k, ans = -1;
        while (l <= r) {
            LL mid = (l + r) / 2;
            if (a[mid].se <= x) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        // cout << "> ";
        if (ans == k) {
            cout << p << endl;
        } else {
            cout << a[ans+1].fi-1 << endl;
        }
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
/*
4 6
4 2 1 2 1 2
8
0
1
2
3
4
5
6
7
*/