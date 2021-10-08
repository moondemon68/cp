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

struct FenwickTree {
    vector<LL> bit;  // binary indexed tree
    LL n;

    FenwickTree(LL n) {
        this->n = n;
        bit.assign(n, 0);
    }

    FenwickTree(vector<LL> a) : FenwickTree(a.size()) {
        for (size_t i = 0; i < a.size(); i++)
            add(i, a[i]);
    }

    void add(LL idx, LL val) {
    for (++idx; idx < n; idx += idx & -idx)
        bit[idx] += val;
    }

    void range_add(LL l, LL r, LL val) {
        add(l, val);
        add(r + 1, -val);
    }

    LL point_query(LL idx) {
        LL ret = 0;
        for (++idx; idx > 0; idx -= idx & -idx)
            ret += bit[idx];
        return ret;
    }
};

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    LL q;
    cin >> q;
    FenwickTree f(q+5);
    LL p = 1;
    while (q--) {
        LL t;
        cin >> t;
        if (t == 1) {
            LL x;
            cin >> x;
            f.range_add(p, p, x);
            p++;
        } else if (t == 2) {
            LL x,y;
            cin >> y >> x;
            f.range_add(1, y, x);
        } else if (t == 0) {
            if (p > 1) {
                p--;
                LL tmp = f.point_query(p);
                f.range_add(p, p, -tmp);
            }
        }
        if (p == 1) cout << "EMPTY";
        else cout << f.point_query(p-1);
        cout << " ";

        // cout << "-> ";
        // for (LL i=1;i<p;i++) cout << f.point_query(i) << " ";
        // cout << endl;
    }
    cout << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
/*
5
1 1
1 2 
0
0
0
*/