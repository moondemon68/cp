#include <bits/stdc++.h>
#define LL long long
using namespace std;

const LL MOD = 1000000007;

LL k(LL x) {
    while (x < 0) x += MOD;
    while (x >= MOD) x -= MOD;
    return x;
}

// kurang
LL j(LL x, LL y) {
    // LL z = y;
    // while (x --> 0) {
    //     z --> 0;
    //     z = k(z);
    // }
    // return z;
    LL z = y-x;
    z = k(z);
    return z;
}

// tambah
LL i(LL x, LL y) {
    // LL z = y;
    // while (x --> 0) {
    //     LL w = MOD;
    //     w --> 0;
    //     // z = j(w, z);
    //     z = k(z - w);
    //     z = k(z);
    // }
    // return z;
    if (x == 0) return y;
    else return k(x+y);
}

// kali
LL h(LL x, LL y) {
    // LL z = 0;
    // while (y --> 0)
    //     z = i(x, z);
    return k(x*y);
}

LL g(LL x, LL y, LL z) {
    // LL w = 0;
    // // w = h(x, y);
    // w = (x*y) % MOD;
    // // w = i(h(y, y), w);
    // w = (y*y) % MOD + w;
    // w %= MOD;
    // // w = j(h(i(x, y), z), w);
    // // w = w - h(i(x,y), z);
    // // w = w - (i(x,y) * z);
    // w = w - (((x+y) * z) % MOD);
    return y*y+x*y-x*z-y*z;
}

LL f(LL x, LL y) {
    LL z = 0;
    while (x --> 0)
        z = g(z, x, y);
    return z;
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

int main() {
    LL t, n, m;
    cin >> t;
    precompute(100000);
    int u[100005];
    memset(u,0,sizeof(u));
    u[1] = 0;
    u[2] = 1;
    for (int i=3;i<=100000;i++) {
        u[i] = u[i-1] + u[i-2]/(i-2);
        // u[i] %= MOD;
    }
    while (t--) {
        LL n,m;
        cin >> n >> m;
        cout << fac u[]
        cout << f(n,m) << endl;
    }
    // cout << j(5,0);
    // cout << g(1,2,5);
    for (int i=1;i<=10;i++) cout << f(70,i) << " ";
    return 0;
}
