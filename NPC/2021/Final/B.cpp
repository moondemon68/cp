// math?
#include <bits/stdc++.h>
#define pb push_back
#define LL long long
#define MOD 1000000007

using namespace std;

LL fpow(LL a, LL b, LL i) {
    LL ans = 1;
    while (b) {
        if (b & 1) {
            ans *= a;
            ans %= MOD;
        }
        a *= a;
        a %= MOD;
        b >>= 1;
    }
    if (i) {
        if (b % 4 == 0) return ans;
        else if (b % 4 == 1) return 0;
        else if (b % 4 == 2) return -ans;
        else return 0;
    }
    return ans;
}

int main () {
    LL i, j, k, l;
    cin >> i >> j >> k >> l;
    LL q;
    cin >> q;
    vector<LL> query;
    while (q--) {
        LL x;
        cin >> x;
        query.pb(x);
    }
    // cout << (1 << 0) << " " << (1 << 1) << " " << (1 << 2) << " " << (1 << 3) << endl;
    for (LL a=0;a*a*a*a <= l;a++) {
        LL rema = l - a*a*a*a;
        for (LL b=0;b*b*b*b <= rema;b++) {
            LL remb = rema - b*b*b*b;
            for (LL c=0;c*c*c*c <= remb;c++) {
                LL remc = remb - c*c*c*c;
                for (LL d=0;d*d*d*d<=remc;d++) {
                    LL remd = remc - d*d*d*d;
                    if (remd != 0) continue;
                    // cout << a << " " << b << " " << c << " " << d << endl;
                    for (LL n = 0; n <= 16*16; n++) {
                        bool yes1 = 0, yes2 = 0, yes3 = 0, yes4 = 0;
                        bool ia = 0, ib = 0, ic = 0, id = 0;
                        if (n & (1 << 0)) a *= -1;
                        if (n & (1 << 1)) b *= -1;
                        if (n & (1 << 2)) c *= -1;
                        if (n & (1 << 3)) d *= -1;
                        if (n & (1 << 4)) ia = 1;
                        if (n & (1 << 5)) ib = 1;
                        if (n & (1 << 6)) ic = 1;
                        if (n & (1 << 7)) id = 1;

                        LL sumi = 0, sumn = 0;  // imaginer, natural
                        if (ia) sumi += a;
                        else sumn += a;
                        if (ib) sumi += b;
                        else sumn += b;
                        if (ic) sumi += c;
                        else sumn += c;
                        if (id) sumi += d;
                        else sumn += d;
                        if (sumi == 0 && sumn == i) yes1 = true;

                        sumi = 0; sumn = 0;
                        if (ia) sumn += -1 * a*a;
                        else sumn += a*a;
                        if (ib) sumn += -1 * b*b;
                        else sumn += b*b;
                        if (ic) sumn += -1 * c*c;
                        else sumn += c*c;
                        if (id) sumn += -1 * d*d;
                        else sumn += d*d;
                        if (sumi == 0 && sumn == j) yes2 = true;

                        sumi = 0; sumn = 0;
                        if (ia) sumi += -1 * a*a*a;
                        else sumn += a*a*a;
                        if (ib) sumi += -1 * b*b*b;
                        else sumn += b*b*b;
                        if (ic) sumi += -1 * c*c*c;
                        else sumn += c*c*c;
                        if (id) sumi += -1 * d*d*d;
                        else sumn += d*d*d;
                        if (sumi == 0 && sumn == k) yes3 = true;

                        if (remd == 0) yes4 = true;

                        if (yes1 && yes2 && yes3 && yes4) {
                            for (auto x : query) {
                                LL ans = 0;
                                ans += fpow(a, x, ia);
                                ans %= MOD;
                                ans += MOD;
                                ans %= MOD;
                                ans += fpow(b, x, ib);
                                ans %= MOD;
                                ans += MOD;
                                ans %= MOD;
                                ans += fpow(c, x, ic);
                                ans %= MOD;
                                ans += MOD;
                                ans %= MOD;
                                ans += fpow(d, x, id);
                                ans %= MOD;
                                ans += MOD;
                                ans %= MOD;
                                cout << "a^" << x << " + b^" << x << " + c^" << x << " + d^" << x << " = " << ans << endl;
                            }
                            return 0;
                        }
                        if (n & (1 << 0)) a *= -1;
                        if (n & (1 << 1)) b *= -1;
                        if (n & (1 << 2)) c *= -1;
                        if (n & (1 << 3)) d *= -1;
                    }
                }
            }
        }
    }
    return 0;
}
/*
-2 30 -44 354
6
1 2 3 69 4 20

276 30708 3728484 457874532
1
1

-172 17630 -1985866 235136642
1
1000000000000000000

-4 4 -4 4
1
1

-262 33802 -4394002 571220002
2
1 5

-4 0 123 -144
-25 35881 -1125181 658868593
1
1

100000000 100000000 100000000 100000000
1
1

*/