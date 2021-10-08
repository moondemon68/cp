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

LL a[200005];
vector<pair<pii, LL>> v;

bool cmp (pair<pii, LL> c, pair<pii, LL> b) {
    if (c.fi.fi == b.fi.fi) return c.fi.se > b.fi.se; 
    else return c.fi.fi < b.fi.fi;
}

// all example usages assume that array a is 1-indexed
const int NMAX = 500000;
pii t[4*NMAX+3];
pii lazy[4*NMAX+3];

// build(1,1,n);
void build(int v, int s, int e) {
    if (s == e){
        t[v] = {a[s], s};
    } else {
        int m = (s+e)/2;
        build(2*v, s, m);
        build(2*v+1, m+1, e);
        if (t[2*v].fi <= t[2*v+1].fi) {
            t[v] = {t[2*v].fi, t[2*v].se};
        } else {
            t[v] = {t[2*v+1].fi, t[2*v+1].se};
        }
    }
}

// updateRange(1,1,n,1,3,5); --> adds a[1..3] with 5
void updateRange(int v, int s, int e, int l, int r, LL val) {
    if (lazy[v] != 0){
        t[v].fi += lazy[v].fi;
        if(s != e){
            lazy[2*v] += lazy[v];
            lazy[2*v+1] += lazy[v];
        }
        lazy[v] = {0,0};
    }
    if (s > e || s > r || l > e) {
        return;
    }
    if (l <= s && e <= r) {
        t[v].fi += val;
        if(s != e){
            lazy[2*v].fi += val;
            lazy[2*v+1].fi += val;
        }
        return;
    }
    int m = (s+e)/2;
    updateRange(2*v, s, m, l, r, val);
    updateRange(2*v+1, m+1, e, l, r, val);
    if (t[2*v].fi <= t[2*v+1].fi) {
        t[v] = {t[2*v].fi, t[2*v].se};
    } else {
        t[v] = {t[2*v+1].fi, t[2*v+1].se};
    }
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
    LL n;
    cin >> n;
    for (LL i=1;i<=n;i++) cin >> a[i];
    LL q;
    cin >> q;
    LL ask[q+5];
    for (LL i=1;i<=q;i++) cin >> ask[i];
    

    // TLE 50
    // LL start = 1;
    // while (start <= n) {
    //     if (a[start] == 0) {
    //         start++;
    //         continue;
    //     }
    //     LL mini = INT_MAX;
    //     LL p = start;
    //     while (p <= n) {
    //         if (a[p] == 0) {
    //             p--;
    //             break;
    //         }
    //         mini = min(mini, a[p]);
    //         p++;
    //     }
    //     if (p > n) p = n;
    //     for (LL i=start;i<=p;i++) {
    //         a[i] -= mini;
    //     }
    //     v.pb({{start, p}, mini});
    // }

    // Subtask 6
    // LL start = 1;
    // LL curmin = 0;
    // while (start <= n) {
    //     if (a[start] - curmin == 0) {
    //         start++;
    //         continue;
    //     }
    //     LL mini = a[start] - curmin;
    //     LL p = n;
    //     v.pb({{start, p}, mini});
    //     curmin += mini;
    //     start++;
    // }

    pii b[n+5];
    for (int i=1;i<=n;i++) {
        b[i] = {a[i], i};
    }
    sort (b+1,b+n+1);
    // for (int i=1;i<=n;i++) cout << b[i].fi << " " << b[i].se << endl;
    b[n+1] = {-1,0};
    set<int> s;
    int last;
    int f[n+5];
    memset (f,0,sizeof(f));
    s.insert(0);
    for (int i=1;i<=n;i++) {
        if (b[i].fi > 0) {
            auto x = (s.upper_bound(b[i].se));
            if (x == s.end()) {
                v.pb({{last, n}, b[i].fi - f[n]});
                s.insert(n);
                f[n] = b[i].fi;
                continue;
            }
            int xx = *x;
            last = *prev(x) + 1;
            cout << last << " " << xx-1  << " " << b[i].fi << " " << f[last-1] << endl;
            v.pb({{last, xx-1}, b[i].fi - f[last-1]});
            last = xx+1;
            s.insert(b[i].se);
            cout << b[i].se << endl;
            f[b[i].se] = b[i].fi;
        } else {
            s.insert(b[i].se);
        }
    }

    // sort (v.begin(), v.end(), cmp);

    // LL last = 1;
    // for (int i=1;i<=n;i++) {
    //     if (b[i].fi == 0) {
    //         LL start = last, fin = b[i].se-1;

    //     }
    // }

    // LL start = 1;
    // while (start <= n) {
    //     if (a[start] == 0) {
    //         start++;
    //         continue;
    //     }
    //     LL mini = INT_MAX;
    //     LL p = start;
    //     while (p <= n) {
    //         if (a[p] == 0) {
    //             p--;
    //             break;
    //         }
    //         mini = min(mini, a[p]);
    //         p++;
    //     }
    //     if (p > n) p = n;
    //     for (LL i=start;i<=p;i++) {
    //         a[i] -= mini;
    //     }
    //     v.pb({{start, p}, mini});
    // }

    // RTE 29
    // vector<LL> ans;
    // for (LL i=0;i<v.size();i++) {
    //     for (LL j=1;j<=v[i].se;j++) {
    //         for (LL k=v[i].fi.fi;k<=v[i].fi.se;k++) {
    //             ans.pb(k);
    //         }
    //     }
    // }
    // for (LL i=1;i<=q;i++) cout << ans[ask[i]-1] << endl;


    vector<LL> p;
    LL cur = 0;
    p.pb(cur);
    for (LL i=0;i<v.size();i++) {
        cur += (v[i].fi.se - v[i].fi.fi + 1) * v[i].se;
        p.pb(cur);
    }

    // DEBUG
    for (LL i=0;i<v.size();i++) {
        cout << v[i].fi.fi << " " << v[i].fi.se << " " << v[i].se << endl;
    }

    for (LL i=1;i<=q;i++) {
        LL x = ask[i];
        LL l = 0, r = v.size()-1, found = -1;
        while (l <= r) {
            LL m = (l + r) / 2;
            if (x > p[m]) {
                found = m;
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        LL pos = x - p[found];
        // cout << found << " " << pos << endl;
        pos--;
        pos %= (v[found].fi.se - v[found].fi.fi + 1);
        cout << v[found].fi.fi + pos << endl;
    }

    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}