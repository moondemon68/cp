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

LL fpow(LL a, LL b) {
    LL ans = 1;
    while (b) {
        if (b & 1) {
            ans *= a;
        }
        a *= a;
        b >>= 1;
    }
    return ans;
}

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    LL n, m, q;
    cin >> n >> m >> q;
    bool y = 0;
    while (q--) {
        LL a, b, c, d;
        cin >> a >> b >> c >> d;
        if (a == b && a == 0) {
            cout << 1 << endl;
            continue;
        }
        LL p = 1;
        for (LL i=1;i<=33;i++) {
            p *= 2;
            if (p > a) break;
        }
        if (a * 2 == p) {
            LL countd = d / (a * 2);
            LL countb = b / (a * 2);
            LL ans = countd - countb;
            if ((b % (a * 2)) < a) {
                ans++;
            }
            cout << ans << endl;
        } else {
            LL cnt = 0;
            vector<LL> v;
            LL x = a;
            while (x) {
                v.pb(x % 2);
                x /= 2;
            }
            reverse(v.begin(), v.end());
            vector<LL> pow;
            for (int i = 0; i < v.size(); i++) {
                LL t = v[i];
                if (t == 0) {
                    cnt++;
                    pow.pb(fpow(2, i));
                }
            }
            LL countd = d / p * fpow(2, cnt);
            LL countb = (b-1) / p * fpow(2, cnt);
            LL remd = d % p;
            LL remb = (b-1) % p;
            // cout << countd << " " << remd << endl;

            LL l = 0, r = (1 << cnt) - 1, answ = 0;
            while (l <= r) {
                LL m = (l + r) / 2;
                LL y = m;
                vector<int> w;
                LL tmp = 0;
                while (w.size() < cnt) {
                    w.pb(y % 2);
                    if (y % 2) tmp += pow[w.size() - 1];
                    y /= 2;
                }
                if (remd >= tmp) {
                    answ = m;
                    l = m + 1;
                } else {
                    r = m - 1;
                }
            }
            countd += answ + 1;

            l = 0, r = (1 << cnt) - 1, answ = 0;
            while (l <= r) {
                LL m = (l + r) / 2;
                LL y = m;
                vector<int> w;
                LL tmp = 0;
                while (w.size() < cnt) {
                    w.pb(y % 2);
                    if (y % 2) tmp += pow[w.size() - 1];
                    y /= 2;
                }
                if (remb >= tmp) {
                    answ = m;
                    l = m + 1;
                } else {
                    r = m - 1;
                }
            }
            countb += answ + 1;

            cout << countd << " " << countb << endl;
            LL ans = countd - countb;
            cout << ans << endl;
        }
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
/*
12 12 3
1 1 9 8
8 8 11 11
4 3 5 9
*/