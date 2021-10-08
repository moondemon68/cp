#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pb push_back
#define sz(a) (int)(a).size()
#define mp(a, b) make_pair((a), (b))
using ll = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;

const ll MOD = 1e9 + 7;
const ll INF = 1e18;
const ll IINF = INT_MAX;
const double PI = acos(-1);


ll ang(pll p) {
    double ang = atan2(p.se, p.fi) * 180 / PI;
    ang += 360;
    while (ang >= 360) ang -= 360;
    return ang;
}

bool cek1(vector<pair<ll, pll>>& ar) {
    double del = ar.back().fi - ar[0].fi;
    // cout << ar.back().fi << ' ' << ar[0].fi << '\n';
    return del <= 180;
}

bool ok(vector<pair<ll, pll>>& a, vector<pair<ll, pll>>& b) {
    if (!a.size() || !b.size()) return true;
    return a.back().fi <= b[0].fi;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ifstream cin("input.txt");

    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<pair<ll, pll>> pos, neg;
        vector<pll> all;
        for (int i = 0; i < n; i++) {
            double x, y;
            cin >> x >> y;
            x *= 100;
            y *= 100;
            int type;
            cin >> type;
            if (type == 1) {
                pos.pb(mp(ang({x, y}), mp(x, y)));
            } else {
                neg.pb(mp(ang({x, y}), mp(x, y)));
            }
        }
        sort(pos.begin(), pos.end());
        sort(neg.begin(), neg.end());
        
        if (!pos.size() || !neg.size()) {
            vector<pair<ll, pll>> ar;
            if (pos.size()) {
                ar = pos;
            } else {
                ar = neg;
            }
            // cout << "disini" << '\n';
            cout << (cek1(ar) ? "YES" : "NO") << '\n';
            continue;
        }
        bool can = false;
        vector<pair<ll, pll>> pos12, neg12, pos34, neg34;
        for (auto it: pos) {
            if (it.fi <= 180) {
                pos12.pb(it);
            } else {
                pos34.pb(it);
            }
        }
        for (auto it: neg) {
            if (it.fi <= 180) {
                neg12.pb(it);
            } else {
                neg34.pb(it);
            }
        }
        for (int i = 0; i < 2; i++) {
            vector<ll> order;
            if (pos12.size()) {
                order.pb(pos12[0].fi);
                order.pb(pos12.back().fi);
            }
            if (neg12.size()) {
                order.pb(neg12[0].fi);
                order.pb(neg12.back().fi);
            }
            if (neg34.size()) {
                order.pb(neg34[0].fi);
                order.pb(neg34.back().fi);
            }
            if (pos34.size()) {
                order.pb(pos34[0].fi);
                order.pb(pos34.back().fi);
            }
            bool cur = true;
            // cout << "CUR ORD";
            // for (int i = 0; i < order.size(); i++) {
            //     cout << order[i] << ' ';
            // }
            // cout << '\n';
            // for (auto it: pos12) {
            //     cout << it.fi << ' ' << it.se.fi << ' ' << it.se.se << '|';
            // } cout << '\n';
            // for (auto it: neg12) {
            //     cout << it.fi << ' ' << it.se.fi << ' ' << it.se.se << '|';
            // } cout << '\n';
            // for (auto it: neg34) {
            //     cout << it.fi << ' ' << it.se.fi << ' ' << it.se.se << '|';
            // } cout << '\n';
            // for (auto it: pos34) {
            //     cout << it.fi << ' ' << it.se.fi << ' ' << it.se.se << '|';
            // } cout << '\n';
            for (int i = 0; i < order.size() - 1; i++) {
                if (order[i] > order[i + 1]) cur = false;
            }
            if (cur) {
                order.clear();
                if (neg12.size()) {
                    order.pb(neg12[0].fi);
                    order.pb(neg12.back().fi);
                }
                if (neg34.size()) {
                    order.pb(neg34[0].fi);
                    order.pb(neg34.back().fi);
                }
                double ang = order.back() - order[0];

                order.clear();
                double atas = 0;
                if (pos12.size()) {
                    atas = pos12.back().fi;
                }
                double bawah = 0;
                if (pos34.size()) {
                    bawah = 360 - pos34[0].fi;
                }
                double ang2 = atas + bawah;
                cur = (ang <= 180) && (ang2 <= 180);
                // cout << ang << ' ' << ang2 << '\n';
                if (cur) {
                    can = cur;
                }

            }
            swap(pos12, neg12);
            swap(pos34, neg34);
        }
        cout << (can ? "YES" : "NO") << '\n';
    }
    return 0;
}