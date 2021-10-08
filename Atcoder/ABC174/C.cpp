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

LL fpow(LL a, LL b, LL k) {
    LL ans = 1;
    while (b) {
        if (b & 1) {
            ans *= a;
            ans %= k;
        }
        a *= a;
        a %= k;
        b >>= 1;
    }
    return ans;
}

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    LL k;
    cin >> k;
    int ans = -2;
    LL p = 0;
    for (int i=0;i<=1000000;i++) {
        // cout << (7 * (fpow(10,i,k)-1) / 9) << endl;
        p += 7 * fpow(10,i, k);
        p %= k;
        if (p == 0) {
            ans = i;
            break;
        }
    }
    cout << ans+1 << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}