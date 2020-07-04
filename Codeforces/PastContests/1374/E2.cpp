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
pii arr[n+5];

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

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    LL n,m,k;
    cin >> n >> m >> k;
    LL t[n+5], a[n+5], b[n+5];
    for (LL i=1;i<=n;i++) {
        cin >> t[i] >> a[i] >> b[i];
        arr[i] = {t[i], i};
    }
    vector<pii> p,q,r;
    vector<pair<LL, pii>> s;
    for (LL i=1;i<=n;i++) {
        if (a[i] == 1 && b[i] == 1) p.pb({t[i], i});
        else if (a[i] == 1) q.pb({t[i], i});
        else if (b[i] == 1) r.pb({t[i], i});
    }
    if ((p.size() + min(q.size(), r.size())) < k) {
        cout << -1 << endl;
        return 0;
    }
    p.pb({0, 0});
    s.pb({0, {0, 0}});
    sort (p.begin(), p.end());
    sort (q.begin(), q.end());
    sort (r.begin(), r.end());
    for (LL i=0;i<min(q.size(), r.size());i++) s.pb({q[i].fi+r[i].fi, {q[i].se, r[i].se}});
    sort (s.begin(), s.end());

    for (LL i=1;i<p.size();i++) p[i].fi += p[i-1].fi;
    for (LL i=1;i<s.size();i++) s[i].fi += s[i-1].fi;

    LL psz = p.size();      // 1
    LL ssz = s.size();      // 2
    LL ans = INT_MAX;
    for (LL i=0;i<=k;i++) {
        if (i < psz && i >= 0 && (k-i) < ssz && (k-i) >= 0) ans = min(ans, p[i].fi+s[k-i].fi);
    }
    cout << ans << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}