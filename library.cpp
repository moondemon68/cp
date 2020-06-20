// Template
// tmpl
// Template for CP
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
    
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}

// Fast Pow
// fpow
// O(logN) power, with modulo MOD
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

// Sieve of Eratosthenes
// sieve
// O(loglogN) sieve