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
        if (l < r) {
            vector<pii> checkpoint;
            LL cur = a[l], curi = l, bcur, bcuri;
            for (LL i = l + 1; i <= r; i++) {
                if (a[i] > cur) {
                    checkpoint.pb({a[i], i});
                    cur = a[i];
                }
            }
            cur = a[l];
            curi = l;
            for (LL i = 0; i < checkpoint.size(); i++) {
                LL len = checkpoint[i].se - curi;
                LL h = checkpoint[i].fi - cur;
                if (len <= h) {
                    ans += 4 * h;
                } else {    // len > h
                    if (i != checkpoint.size() - 1) {
                        continue;
                    }
                    ans += 4 * h;
                    ans += 2 * (len - h);
                }
                cur = checkpoint[i].fi;
                curi = checkpoint[i].se;
            }
            vector<pii> backcheckpoint;
            bcur = a[r];
            for (LL i = r - 1; i >= l; i--) {
                if (a[i] > bcur) {
                    backcheckpoint.pb({a[i], i});
                    bcur = a[i];
                    if (bcur == cur) {
                        break;
                    }
                }
            }
            bcur = a[r];
            bcuri = r;
            for (LL i = 0; i < backcheckpoint.size(); i++) {
                LL len = bcuri - backcheckpoint[i].se;
                LL h = backcheckpoint[i].fi - bcur;
                if (len <= h) {
                    ans += h;
                } else {    // len > h
                    if (i != backcheckpoint.size() - 1) {
                        continue;
                    }
                    ans += 2 * len - h;
                }
                bcur = backcheckpoint[i].fi;
                bcuri = backcheckpoint[i].se;
            }
            ans += 2 * (bcuri - curi);
        } else {
            l = n + 1 - l;
            r = n + 1 - r;
            vector<pii> checkpoint;
            LL cur = b[l], curi = l, bcur, bcuri;
            for (LL i = l + 1; i <= r; i++) {
                if (b[i] > cur) {
                    checkpoint.pb({b[i], i});
                    cur = b[i];
                }
            }
            cur = b[l];
            curi = l;
            for (LL i = 0; i < checkpoint.size(); i++) {
                LL len = checkpoint[i].se - curi;
                LL h = checkpoint[i].fi - cur;
                if (len <= h) {
                    ans += 4 * h;
                } else {    // len > h
                    if (i != checkpoint.size() - 1) {
                        continue;
                    }
                    ans += 4 * h;
                    ans += 2 * (len - h);
                }
                cur = checkpoint[i].fi;
                curi = checkpoint[i].se;
            }
            vector<pii> backcheckpoint;
            bcur = b[r];
            for (LL i = r - 1; i >= l; i--) {
                if (b[i] > bcur) {
                    backcheckpoint.pb({b[i], i});
                    bcur = b[i];
                    if (bcur == cur) {
                        break;
                    }
                }
            }
            bcur = b[r];
            bcuri = r;
            for (LL i = 0; i < backcheckpoint.size(); i++) {
                LL len = bcuri - backcheckpoint[i].se;
                LL h = backcheckpoint[i].fi - bcur;
                if (len <= h) {
                    ans += h;
                } else {    // len > h
                    if (i != backcheckpoint.size() - 1) {
                        continue;
                    }
                    ans += 2 * len - h;
                }
                bcur = backcheckpoint[i].fi;
                bcuri = backcheckpoint[i].se;
            }
            ans += 2 * (bcuri - curi);
        }
        cout << ans << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
/*
6
1 4 4 4 6 10
1
1 6
38

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

5
2 9 4 5 8
1
1 5


*/