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
pii t[4*NMAX+3];
pii lazy[4*NMAX+3];
pii a[NMAX+3];

// build(1,1,n);
void build(LL v, LL s, LL e) {
    if (s == e){
        t[v] = a[s];
    } else {
        LL m = (s+e)/2;
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
void updateRange(LL v, LL s, LL e, LL l, LL r, LL val) {
    if (lazy[v].fi != 0){
        t[v].fi += lazy[v].fi;
        if(s != e){
            lazy[2*v].fi += lazy[v].fi;
            lazy[2*v+1].fi += lazy[v].fi;
        }
        lazy[v].fi = 0;
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
    LL m = (s+e)/2;
    updateRange(2*v, s, m, l, r, val);
    updateRange(2*v+1, m+1, e, l, r, val);
    // t[v] = min(t[2*v], t[2*v+1]);
    if (t[2*v].fi <= t[2*v+1].fi) {
        t[v] = t[2*v];
    } else {
        t[v] = t[2*v+1];
    }
}

// queryRange(1,1,n,1,3); --> find min between a[1..3]
pii queryRange(LL v, LL s, LL e, LL l, LL r){
    if (s > e || s > r || l > e) {
        return {(LL)INT_MAX * (LL)INT_MAX, 0};
    }
    if (lazy[v].fi != 0) {
        t[v].fi += lazy[v].fi;
        if (s != e) {
            lazy[2*v].fi += lazy[v].fi;
            lazy[2*v+1].fi += lazy[v].fi;
        }
        lazy[v].fi = 0;
    }
    if (l <= s && e <= r) {
        return t[v];
    }
    LL m = (s+e)/2;
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
    for (LL tt=0;tt<=5;tt++) {
        ifstream cin("level7/level7_" + to_string(tt) + ".in");
        ofstream cout("level7/level7_" + to_string(tt) + ".out");
        LL maxPower, maxBill, maxCon;
        cin >> maxPower >> maxBill >> maxCon;
        LL n;
        cin >> n;
        for (LL i=1;i<=n;i++) {
            cin >> a[i].fi;
            a[i].se = i-1;
        }
        LL left[n+5], con[n+5], tot[n+5];
        memset (tot,0,sizeof(tot));
        LL h;
        cin >> h;
        cout << h << '\n';
        double bill = 0;
        for (LL j=1;j<=h;j++) {
            for (LL i=1;i<=n;i++) con[i] = maxCon;
            for (LL i=1;i<=n;i++) left[i] = 0;
            for (LL i=1;i<=4*n;i++) {
                t[i].fi = 0LL;
                t[i].se = 0LL;
                lazy[i].fi = 0LL;
                lazy[i].se = 0LL;
            }
            build(1,1,n);
            LL m;
            cin >> m;
            cout << j << "\n";
            cout << m << '\n';
            for (LL i=1;i<=m;i++) {
                LL p,x,l,r;
                cin >> p >> x >> l >> r;
                // cerr << p << endl;
                vector<pii> v, answer;
                while (x) {
                    pii ans = queryRange(1,1,n,l+1,r+1);
                    v.pb(ans);
                    LL k = min(1LL, min(maxPower-left[ans.se+1], x));
                    x -= k;
                    updateRange(1,1,n,ans.se+1,ans.se+1,(LL)INT_MAX * (LL)INT_MAX/2);
                    // cout << ans.fi << " ";
                    if (ans.fi >= (LL)INT_MAX * (LL)INT_MAX) {
                        cerr << "FORCED MAX: " << tt << " " << j << " " << i << " " << ans.se << endl;
                        break;
                    }
                    answer.pb({ans.se, k});
                    left[ans.se+1] += k;
                    con[ans.se+1]--;
                    // cout << ans.se << " " << k << " ";
                }
                for (auto tp : v) {
                    if (left[tp.se+1] < maxPower && con[tp.se+1] > 0) updateRange(1,1,n,tp.se+1,tp.se+1,-(LL)INT_MAX * (LL)INT_MAX/2 + a[tp.se+1].fi);
                }
                // sort (answer.begin(), answer.end());
                cout << p << " ";
                for (auto tp : answer) {
                    cout << tp.fi << " " << tp.se << " ";
                    if (tp.fi < l || tp.fi > r) cerr << "INVALID RANGE: " << tt << " " << i << endl;
                }
                cout << '\n';
                // cout << p << " " << queryRange(1,1,n,l+1,r+1).se << " " << x << '\n';
            }
            for (LL i=1;i<=n;i++) {
                tot[i] += left[i];
            }
        }
        for (LL i=1;i<=n;i++) {
            bill += (double)a[i].fi * tot[i] * ((double)1 + (double)(tot[i]/maxPower));
        }
        cerr << fixed << setprecision(0) << bill << " " << maxBill << endl;
        // if (t == 2) for (LL i=1;i<=n;i++) cerr << i << " " << left[i] << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}