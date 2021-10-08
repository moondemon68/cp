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

const int MAXN = 2000000;
LL fac[MAXN+5], inv[MAXN+5];

// don't forget to call this function
void precompute(LL x) {
    fac[0] = 1;
    inv[0] = 1;
    for (LL i=1;i<=x;i++) {
        fac[i] = fac[i-1] * i;
        fac[i] %= MOD;
        inv[i] = fpow(fac[i], MOD-2);
    }
}

LL c(LL n, LL k) {
    if (n < k) return 0;
    LL ret = fac[n];
    ret *= inv[k];
    ret %= MOD;
    ret *= inv[n-k];
    ret %= MOD;
    return ret;
}

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // ofstream cout("Hdebug.txt");
    precompute(200000);
    // for (int n=1;n<=20;n++) {
    //     for (int m=1;m<=20;m++) {
    //         cout << "> " << n << " " << m << endl;
    //         for (int k=0;k<=min(n, m);k++) {
    //             int cur = 0;
    //             for (int j=0;j<=k;j++) {
    //                 cur += c(n, j) * c(m, k-j);
    //             }
    //             cout << cur << " ";
    //         }
    //         cout << endl;
    //     }
    //     cout << endl;
    // }
    int tc;
    cin >> tc;
    LL tot = 0;
    while (tc--) {
        LL n,m,k;
        cin >> n >> m >> k;
        tot += c(n + m, k);
        tot %= MOD;
    }
    cout << tot << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}

/*
1 16 36 16 1

36 68 70
*/