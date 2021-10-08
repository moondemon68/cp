// Template
// tmpl
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
vector<LL> p;
bool prime[200005];
void sieve(LL x) {
    memset (prime,1,sizeof(prime));
    prime[1] = 0;
    for (LL i=2;i*i<=x;i++) {
        if (!prime[i]) continue;
        for (LL j=i*i;j<=x;j+=i) {
            prime[j] = 0;
        }
    }
    for (LL i=2;i<=x;i++) {
        if (prime[i]) p.pb(i);
    }
}

// Segtree RMQ with Lazy
// all example usages assume that array a is 1-indexed
const int NMAX = 500000;
LL t[4*NMAX+3];
LL lazy[4*NMAX+3];
LL a[NMAX+3];

// build(1,1,n);
void build(int v, int s, int e) {
    if (s == e){
        t[v] = a[s];
    } else {
        int m = (s+e)/2;
        build(2*v, s, m);
        build(2*v+1, m+1, e);
        t[v] = min(t[2*v], t[2*v+1]);
    }
}

// updateRange(1,1,n,1,3,5); --> adds a[1..3] with 5
void updateRange(int v, int s, int e, int l, int r, LL val) {
    if (lazy[v] != 0){
        t[v] += lazy[v];
        if(s != e){
            lazy[2*v] += lazy[v];
            lazy[2*v+1] += lazy[v];
        }
        lazy[v] = 0;
    }
    if (s > e || s > r || l > e) {
        return;
    }
    if (l <= s && e <= r) {
        t[v] += val;
        if(s != e){
            lazy[2*v] += val;
            lazy[2*v+1] += val;
        }
        return;
    }
    int m = (s+e)/2;
    updateRange(2*v, s, m, l, r, val);
    updateRange(2*v+1, m+1, e, l, r, val);
    t[v] = min(t[2*v], t[2*v+1]);
}

// queryRange(1,1,n,1,3); --> find min between a[1..3]
LL queryRange(int v, int s, int e, int l, int r){
    if (s > e || s > r || l > e) {
        return INT_MAX;
    }
    if (lazy[v] != 0) {
        t[v] += lazy[v];
        if (s != e) {
            lazy[2*v] += lazy[v];
            lazy[2*v+1] += lazy[v];
        }
        lazy[v] = 0;
    }
    if (l <= s && e <= r) {
        return t[v];
    }
    int m = (s+e)/2;
    LL p1 = queryRange(2*v, s, m, l, r);
    LL p2 = queryRange(2*v+1, m+1, e, l, r);
    return min(p1, p2);
}

// Segtree sum with lazy
// all example usages assume that array a is 1-indexed
const int NMAX = 500000;
LL t[4*NMAX+3];
LL lazy[4*NMAX+3];
LL a[NMAX+3];

// build(1,1,n);
void build(int v, int s, int e) {
    if (s == e){
        t[v] = a[s];
    } else {
        int m = (s+e)/2;
        build(2*v, s, m);
        build(2*v+1, m+1, e);
        t[v] = t[2*v] + t[2*v+1];
    }
}

// updateRange(1,1,n,1,3,5); --> adds a[1..3] with 5
void updateRange(int v, int s, int e, int l, int r, LL val) {
    if (lazy[v] != 0){
        t[v] += lazy[v];
        if(s != e){
            lazy[2*v] += lazy[v];
            lazy[2*v+1] += lazy[v];
        }
        lazy[v] = 0;
    }
    if (s > e || s > r || l > e) {
        return;
    }
    if (l <= s && e <= r) {
        t[v] += val;
        if(s != e){
            lazy[2*v] += val;
            lazy[2*v+1] += val;
        }
        return;
    }
    int m = (s+e)/2;
    updateRange(2*v, s, m, l, r, val);
    updateRange(2*v+1, m+1, e, l, r, val);
    t[v] = t[2*v] + t[2*v+1];
}

// queryRange(1,1,n,1,3); --> find sum of a[1..3]
LL queryRange(int v, int s, int e, int l, int r){
    if (s > e || s > r || l > e) {
        return 0;
    }
    if (lazy[v] != 0) {
        t[v] += lazy[v];
        if (s != e) {
            lazy[2*v] += lazy[v];
            lazy[2*v+1] += lazy[v];
        }
        lazy[v] = 0;
    }
    if (l <= s && e <= r) {
        return t[v];
    }
    int m = (s+e)/2;
    LL p1 = queryRange(2*v, s, m, l, r);
    LL p2 = queryRange(2*v+1, m+1, e, l, r);
    return p1 + p2;
}


// DSU
LL pset[100005], n;
void init() {
    for (LL i=1;i<=n;i++) pset[i] = i;
}
LL findSet(LL u) {
    return pset[u] == u ? u : pset[u] = findSet(pset[u]);
}
LL isSameSet(LL u, LL v) {
    return findSet(u) == findSet(v);
}
void unionSet(LL u, LL v) {
    pset[findSet(u)] = findSet(v);
}