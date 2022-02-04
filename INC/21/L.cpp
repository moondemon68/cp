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
    int n, m;
    cin >> n >> m;
    pii a[n+5], b[n+5];
    for (int i=1;i<=n;i++) cin >> a[i].fi >> a[i].se;
    map<pii, int> p;
    map<pii, int> q;
    for (int i=1;i<=n;i++) {
        if (a[i].fi != -1 && a[i].se != -1) {
            if (p[{a[i].fi, a[i].se}] == 1) {
                cout << "NO" << endl;
                return 0;
            }
            p[{a[i].fi, a[i].se}] = 1;
            q[{a[i].se, a[i].fi}] = 1;
        }
        b[i].fi = a[i].se;
        b[i].se = a[i].fi;
    }
    int last[m+5];
    for (int i=1;i<=m;i++) last[i] = 1;
    for (int i=1;i<=n;i++) {
        if (a[i].fi == -1 && a[i].se != -1) {
            while (last[a[i].se] <= m && p[{last[a[i].se], a[i].se}] == 1) {
                last[a[i].se]++;
            }
            a[i].fi = last[a[i].se];
            p[{a[i].fi, a[i].se}] = 1;
        }
    }
    for (int i=1;i<=m;i++) last[i] = 1;
    for (int i=1;i<=n;i++) {
        if (a[i].fi != -1 && a[i].se == -1) {
            while (last[a[i].se] <= m && p[{a[i].fi, last[a[i].fi]}] == 1) {
                last[a[i].fi]++;
            }
            a[i].se = last[a[i].fi];
            p[{a[i].fi, a[i].se}] = 1;
        }
    }
    for (int i=1;i<=m;i++) last[i] = 1;
    int cur = 0;
    for (int i=1;i<=n;i++) {
        if (a[i].fi == -1 && a[i].se == -1) {
            while (p[{cur/m+1, cur%m+1}] == 1) {
                cur++;
            }
            a[i] = {cur/m+1, cur%m+1};
            p[{a[i].fi, a[i].se}] = 1;
        }
    }
    bool y = 1;
    for (int i=1;i<=n;i++) {
        if (a[i].fi > m || a[i].se > m) y = 0;
    }
    if (y) {
        cout << "YES" << endl;
        for (int i=1;i<=n;i++) cout << a[i].fi << " " << a[i].se << endl;
        return 0;
    }

    // kanan dulu
    for (int i=1;i<=m;i++) last[i] = 1;
    for (int i=1;i<=n;i++) {
        if (b[i].fi == -1 && b[i].se != -1) {
            while (last[b[i].se] <= m && q[{last[b[i].se], b[i].se}] == 1) {
                last[b[i].se]++;
            }
            b[i].fi = last[b[i].se];
            q[{b[i].fi, b[i].se}] = 1;
        }
    }
    for (int i=1;i<=m;i++) last[i] = 1;
    for (int i=1;i<=n;i++) {
        if (b[i].fi != -1 && b[i].se == -1) {
            while (last[b[i].se] <= m && q[{b[i].fi, last[b[i].fi]}] == 1) {
                last[b[i].fi]++;
            }
            b[i].se = last[b[i].fi];
            q[{b[i].fi, b[i].se}] = 1;
        }
    }
    for (int i=1;i<=m;i++) last[i] = 1;
    cur = 0;
    for (int i=1;i<=n;i++) {
        if (b[i].fi == -1 && b[i].se == -1) {
            while (q[{cur/m+1, cur%m+1}] == 1) {
                cur++;
            }
            b[i] = {cur/m+1, cur%m+1};
            q[{b[i].fi, b[i].se}] = 1;
        }
    }
    y = 1;
    for (int i=1;i<=n;i++) {
        if (b[i].fi > m || b[i].se > m) y = 0;
    }
    if (y) {
        cout << "YES" << endl;
        for (int i=1;i<=n;i++) cout << b[i].se << " " << b[i].fi << endl;
    } else {
        cout << "NO" << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
/*
6 3
-1 1
-1 1
-1 1
2 -1
1 2
3 -1

9 3
1 3
2 -1
3 -1
3 2
2 2
-1 -1
-1 1
1 2
2 -1

6 3
1 -1
1 -1
1 -1
2 2
2 1
-1 3
*/