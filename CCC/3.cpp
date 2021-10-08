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
const int NMAX = 500000;
pii t[4*NMAX+3];
pii lazy[4*NMAX+3];
pii a[NMAX+3];

// build(1,1,n);
void build(int v, int s, int e) {
    if (s == e){
        t[v] = a[s];
    } else {
        int m = (s+e)/2;
        build(2*v, s, m);
        build(2*v+1, m+1, e);
        if (t[2*v].fi <= t[2*v+1].fi) {
            t[v] = t[2*v];
        } else {
            t[v] = t[2*v+1];
        }
        // t[v] = min(t[2*v], t[2*v+1]);
    }
}

// updateRange(1,1,n,1,3,5); --> adds a[1..3] with 5
// void updateRange(int v, int s, int e, int l, int r, LL val) {
//     if (lazy[v] != 0){
//         t[v] += lazy[v];
//         if(s != e){
//             lazy[2*v] += lazy[v];
//             lazy[2*v+1] += lazy[v];
//         }
//         lazy[v] = 0;
//     }
//     if (s > e || s > r || l > e) {
//         return;
//     }
//     if (l <= s && e <= r) {
//         t[v] += val;
//         if(s != e){
//             lazy[2*v] += val;
//             lazy[2*v+1] += val;
//         }
//         return;
//     }
//     int m = (s+e)/2;
//     updateRange(2*v, s, m, l, r, val);
//     updateRange(2*v+1, m+1, e, l, r, val);
//     t[v] = min(t[2*v], t[2*v+1]);
// }

// queryRange(1,1,n,1,3); --> find min between a[1..3]
pii queryRange(int v, int s, int e, int l, int r){
    if (s > e || s > r || l > e) {
        return {INT_MAX, 0};
    }
    // if (lazy[v] != 0) {
    //     t[v] += lazy[v];
    //     if (s != e) {
    //         lazy[2*v] += lazy[v];
    //         lazy[2*v+1] += lazy[v];
    //     }
    //     lazy[v] = 0;
    // }
    if (l <= s && e <= r) {
        return t[v];
    }
    int m = (s+e)/2;
    pii p1 = queryRange(2*v, s, m, l, r);
    pii p2 = queryRange(2*v+1, m+1, e, l, r);
    if (p1.fi <= p2.fi) return p1; else return p2;
    // return min(p1, p2);
}

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    for (LL t=1;t<=5;t++) {
        ifstream cin("level3/level3_" + to_string(t) + ".in");
        ofstream cout("level3/level3_" + to_string(t) + ".out");
        LL n;
        cin >> n;
        for (LL i=1;i<=n;i++) {
            cin >> a[i].fi;
            a[i].se = i-1;
        }
        build(1,1,n);
        LL m;
        cin >> m;
        cout << m << '\n';
        for (LL i=1;i<=m;i++) {
            LL p,x,l,r;
            cin >> p >> x >> l >> r;
            cout << p << " " << queryRange(1,1,n,l+1,r+1).se << " " << x << '\n';
        }
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}