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

LL g(LL x, LL y, LL z) {
    LL ans = y*y;
    ans += x*y;
    ans -= x*z;
    ans -= y*z;
    ans %= MOD;
    ans += MOD;
    ans %= MOD;
    return ans;
}

LL f(LL x, LL y) {
    LL z = 0;
    while (x --> 0) {
        z = g(z, x, y);
    }
    return z;
}

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc;
    cin >> tc;
    while (tc--) {
        LL n,m;
        cin >> n >> m;
        if (n > m) n = m;
        cout << f(n,m) << endl;

    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}