#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define INF 1234567890
#define pii pair<LL,LL>
#define LL long long
using namespace std;

// all example usages assume that array a is 1-indexed
const LL NMAX = 500000;
LL t[4*NMAX+3];
LL lazy[4*NMAX+3];
LL a[NMAX+3];

// build(1,1,n);
void build(LL v, LL s, LL e) {
    if (s == e){
        t[v] = a[s];
    } else {
        LL m = (s+e)/2;
        build(2*v, s, m);
        build(2*v+1, m+1, e);
        t[v] = min(t[2*v], t[2*v+1]);
    }
}

// updateRange(1,1,n,1,3,5); --> adds a[1..3] with 5
void updateRange(LL v, LL s, LL e, LL l, LL r, LL val) {
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
    LL m = (s+e)/2;
    updateRange(2*v, s, m, l, r, val);
    updateRange(2*v+1, m+1, e, l, r, val);
    t[v] = min(t[2*v], t[2*v+1]);
}

// queryRange(1,1,n,1,3); --> find min between a[1..3]
LL queryRange(LL v, LL s, LL e, LL l, LL r){
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
    LL m = (s+e)/2;
    LL p1 = queryRange(2*v, s, m, l, r);
    LL p2 = queryRange(2*v+1, m+1, e, l, r);
    return min(p1, p2);
}

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    LL n;
    cin >> n;
    bool bid[n+5];
    memset (bid,0,sizeof(bid));
    for (LL i=1;i<=n;i++) {
        cin >> a[i];
        a[i]--;
    }
    build(1,1,n);

    LL m;
    cin >> m;
    LL ans = 0;
    while (m--) {
        LL x;
        cin >> x;
        // segtree + binser
        // lebih besar samadengan
        LL l = 1, h = n, tans = INT_MAX;
        while (l <= h) {
            LL mid = (l + h) / 2;
            LL q = queryRange(1,1,n,1,mid);
            if (x > q) {
                tans = mid;
                h = mid-1;
            } else {
                l = mid+1;
            }
        }

        // cout << x << " " << tans << " " << tans2 << endl;
        if (tans != INT_MAX) {
            updateRange(1,1,n,tans,tans,x-a[tans]);
            a[tans] = x;
            bid[tans] = 1;
        }
    }
    for (LL i=1;i<=n;i++) if (bid[i]) ans++;
    cout << ans << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
/*
5
2 1 2 2 2
5
2 2 2 2 2
*/