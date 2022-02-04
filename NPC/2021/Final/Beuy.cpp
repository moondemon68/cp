// math?
#include <bits/stdc++.h>
#define pb push_back
#define LL long long
#define MOD 1000000007

using namespace std;

LL fpow(LL a, LL b) {
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
    return ans;
}

int main () {
    // LL i, j, k, l;
    // cin >> i >> j >> k >> l;
    vector<int> query;
    for (int aa = -100; aa <= 100; aa++) {
        cout << aa << endl;
        for (int bb = -100; bb <= 100; bb++) {
            for (int cc = -100; cc <= 100; cc++) {
                for (int dd = -100; dd <= 100; dd++) {
                    LL i = aa + bb + cc + dd;
                    LL j = aa * aa + bb * bb + cc * cc + dd * dd;
                    LL k = aa * aa * aa + bb * bb * bb + cc * cc * cc + dd * dd* dd;
                    LL l = aa * aa * aa * aa + bb * bb * bb * bb + cc * cc * cc * cc + dd * dd * dd * dd;
                    bool yes = 0;
                    for (LL a=0;a*a*a*a <= l;a++) {
                        LL rema = l - a*a*a*a + 1;
                        for (LL b=0;b*b*b*b <= rema;b++) {
                            LL remb = rema - b*b*b*b + 1;
                            for (LL c=0;c*c*c*c <= remb;c++) {
                                LL remc = remb - c*c*c*c + 1;
                                for (LL d=0;d*d*d*d<=remc;d++) {
                                    LL remd = remc - d*d*d*d + 1;
                                    if ((a*a + b*b + c*c + d*d) != j) continue; // 2
                                    for (LL n = 0; n <= 16; n++) {
                                        bool yes1 = 0, yes3 = 0, yes4 = 0;
                                        if (n & (1 << 0)) a *= -1;
                                        if (n & (1 << 1)) b *= -1;
                                        if (n & (1 << 2)) c *= -1;
                                        if (n & (1 << 3)) d *= -1;
                                        // cout << a << " " << b << " " << c << " " << d << " " << (a + b + c + d) << " " << (a*a*a + b*b*b + c*c*c + d*d*d) << endl;
                                        if ((a + b + c + d) == i) yes1 = true;
                                        if ((a*a*a + b*b*b + c*c*c + d*d*d) == k) yes3 = true;
                                        if ((a*a*a*a + b*b*b*b + c*c*c*c + d*d*d*d) == l) yes4 = true;
                                        // cout << yes1 << " " << yes3 << endl;
                                        if (yes1 && yes3 && yes4) {
                                            // cout << a << " " << b << " " << c << " " << d << endl;
                                            for (auto x : query) {
                                                LL ans = 0;
                                                ans += fpow(a, x);
                                                ans %= MOD;
                                                ans += MOD;
                                                ans %= MOD;
                                                ans += fpow(b, x);
                                                ans %= MOD;
                                                ans += MOD;
                                                ans %= MOD;
                                                ans += fpow(c, x);
                                                ans %= MOD;
                                                ans += MOD;
                                                ans %= MOD;
                                                ans += fpow(d, x);
                                                ans %= MOD;
                                                ans += MOD;
                                                ans %= MOD;
                                                cout << "a^" << x << " + b^" << x << " + c^" << x << " + d^" << x << " = " << ans << endl;
                                            }
                                            yes = 1;
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
                    if (!yes) {
                        cout << i << " " << j << " " << k << " " << l << " " << aa << " " << bb << " " << cc << " " << dd << endl;
                        assert(0 == 1);
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
*/