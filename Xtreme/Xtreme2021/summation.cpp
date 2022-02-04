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
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int p = 1000, q = 2;
    int n = 2;
    LL ans = 0;
    for (int i=1;i<=q;i++) {
        for (int j=0;j<i;j++) {
            LL cur = 1;
            if (j % 2 == 1) cur *= -1;
            cur *= fpow(i-j, q);
            cur %= MOD;
            cur += MOD;
            cur %= MOD;
            for (int k=n-i+q+1; k>n-1; k--) {
                cur *= k;
                cur %= MOD;
            }
            for (int k=q+1;k>j;k--) {
                cur *= k;
                cur %= MOD;
            }
            ans += cur;
            ans %= MOD;
            cout << cur << endl;
        }
    }
    cout << ans << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}