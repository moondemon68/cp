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
    cout << 13 * fpow(4, MOD-2);
    cout << endl;
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