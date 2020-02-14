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
    int n,m,k;
    cin >> n >> m >> k;
    n--;
    m--;
    vector<pair<int, string>> v;
    int kanan = min(m, k);
    k -= kanan;
    if (kanan != 0) v.pb({kanan, "R"});
    int kiri = min(m, k);
    k -= kiri;
    if (kiri != 0) v.pb({kiri, "L"});
    int p = 0, q = 0;
    while (k > 0 && p < n) {
        k--;
        v.pb({1, "D"});
        if (k == 0) break;
        kanan = min(m, k);
        k -= kanan;
        q += kanan;
        if (kanan != 0) v.pb({kanan, "R"});
        if (k == 0) break;
        kiri = k/3;
        if (kiri > m) kiri = m;
        k -= kiri*3;
        q -= kiri;
        if (kiri != 0) v.pb({kiri, "UDL"});
        if (k == 0) break;
        if (kiri < m) {
            if (k == 2) {
                k -= 2;
                v.pb({1, "U"});
                v.pb({1, "D"});
            } else if (k == 1) {
                k--;
                v.pb({1, "U"});
            }
        }
        kiri = min(q, k);
        if (kiri != 0) v.pb({kiri, "L"});
        q -= kiri;
        p++;
        if (k <= 2 && p >= 1) {
            if (k == 1) {
                k--;
                v.pb({1, "U"});
            } else if (k == 2 && kiri > 1){
                k--;
                v.pb({1, "L"});
                k--;
                v.pb({1, "U"});
            }
        }
    }
    if (k > 0) {
        int naik = min(n, k);
        k -= naik;
        if (naik != 0) v.pb({naik, "U"});
    }

    if (k == 0) {
        cout << "YES" << endl;
        cout << v.size() << endl;
        for (int i=0;i<v.size();i++) {
            cout << v[i].fi << " " << v[i].se << endl;
        }
    } else {
        cout << "NO" << endl;
    }
    cerr << v.size() << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}