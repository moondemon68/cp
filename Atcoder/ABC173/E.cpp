#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
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
    LL n,k, tk;
    cin >> n >> k;
    tk = k;
    LL a[n+5];
    for (LL i=1;i<=n;i++) cin >> a[i];
    vector<LL> p,m;
    LL nol = 0;
    for (LL i=1;i<=n;i++) {
        if (a[i] > 0) {
            p.pb(a[i]);
        } else if (a[i] < 0) {
            m.pb(a[i]);
        } else {
            nol++;
        }
    }
    bool positif = 0;
    LL ps = p.size(), ms = m.size();
    // if (p.size() >= k) positif = 1;
    // if (ps == 0 && k % 2 == 1) positif = 1;
    positif = 1;
    vector<LL> ansn,ansp;
    if (positif) {
        // if (nol) {
            // cout << 0 << endl;
        // } else {     // negatif
            sort(p.begin(), p.end());
            sort (m.begin(), m.end());
            reverse(m.begin(), m.end());
            LL pp = 0, mp = 0;
            while (k >= 2) {
                if (pp <= ps-2 && mp <= ms-2) {
                    if (p[pp] * p[pp+1] <= m[mp] * m[mp+1]) {
                        ansn.pb(p[pp]);
                        ansn.pb(p[pp+1]);
                        pp += 2;
                        k -= 2;
                    } else {
                        ansn.pb(m[mp]);
                        ansn.pb(m[mp+1]);
                        mp += 2;
                        k -= 2;
                    }
                } else if (pp <= ps-2) {
                    ansn.pb(p[pp]);
                    ansn.pb(p[pp+1]);
                    pp += 2;
                    k -= 2;
                } else if (mp <= ms-2) {
                    ansn.pb(m[mp]);
                    ansn.pb(m[mp+1]);
                    mp += 2;
                    k -= 2;
                } else {
                    break;
                }
            }
            if (k == 1) {
                k--;
                if (mp < ms) ansn.pb(m[mp]);
            }
        // }
    } 
    k = tk;
    if (positif) {    // positif
        sort (p.begin(), p.end());
        reverse (p.begin(), p.end());
        sort (m.begin(), m.end());
        LL pp = 0, mp = 0;
        while (k >= 2) {
            if (pp <= ps-2 && mp <= ms-2) {
                if (p[pp] * p[pp+1] >= m[mp] * m[mp+1]) {
                    ansp.pb(p[pp]);
                    ansp.pb(p[pp+1]);
                    pp += 2;
                    k -= 2;
                } else {
                    ansp.pb(m[mp]);
                    ansp.pb(m[mp+1]);
                    mp += 2;
                    k -= 2;
                }
            } else if (pp <= ps-2) {
                ansp.pb(p[pp]);
                ansp.pb(p[pp+1]);
                pp += 2;
                k -= 2;
            } else if (mp <= ms-2) {
                ansp.pb(m[mp]);
                ansp.pb(m[mp+1]);
                mp += 2;
                k -= 2;
            } else {
                break;
            }
        }
        if (k == 1) {
            k--;
            if (pp < ps) ansp.pb(p[pp]);
        }
    }
    while (ansn.size() < tk) ansn.pb(0);
    LL cntminesp = 0;
    for (auto x : ansp) {
        if (x < 0) cntminesp++;
    }
        cerr << ansp.size()+nol << endl;
    if (cntminesp % 2 == 0 && (ansp.size()+nol >= tk)) {
        LL tmp = 1;
        while (ansp.size() < tk) ansp.pb(0);
        for (auto x : ansp) {
            tmp *= x;
            tmp %= MOD;
            tmp += MOD;
            tmp %= MOD;
        }
        cout << tmp << endl;
    } else {
        LL tmp = 1;
        for (auto x : ansn) {
            tmp *= x;
            tmp %= MOD;
            tmp += MOD;
            tmp %= MOD;
        }
        cout << tmp << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}