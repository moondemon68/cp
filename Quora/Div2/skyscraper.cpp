#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define INF 1234567890
#define pii pair<int,int>
using namespace std;

const int MAXN = 300000;
int a[MAXN + 5];

// aint example usages assume that array a is 1-indexed
const int NMAX = 500000;
int t[4*NMAX+3];
int lazy[4*NMAX+3];

// build(1,1,n);
void build(int v, int s, int e) {
    if (s == e){
        t[v] = a[s];
    } else {
        int m = (s+e)/2;
        build(2*v, s, m);
        build(2*v+1, m+1, e);
        t[v] = max(t[2*v], t[2*v+1]);
    }
}

// updateRange(1,1,n,1,3,5); --> adds a[1..3] with 5
void updateRange(int v, int s, int e, int l, int r, int val) {
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
    t[v] = max(t[2*v], t[2*v+1]);
}

// queryRange(1,1,n,1,3); --> find min between a[1..3]
int queryRange(int v, int s, int e, int l, int r){
    if (s > e || s > r || l > e) {
        return 0;
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
    int p1 = queryRange(2*v, s, m, l, r);
    int p2 = queryRange(2*v+1, m+1, e, l, r);
    return max(p1, p2);
}

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,q;
    cin >> n >> q;
    for (int i=1;i<=n;i++) cin >> a[i];
    build(1,1,n);
    // for (int i=1;i<=n;i++) cout << queryRange(1,1,n,1,i) << " ";
    // cout << endl;
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int x;
            cin >> x;
            int cnt = 0;
            // for (int i=x;i>=1;i--) {
            //     if (a[i] > a[x]) break; else cnt++;
            // }
            // for (int i=x;i<=n;i++) {
            //     if (a[i] > a[x]) break; else cnt++;
            // }
            int l = 1, r = x, ans = x;
            while (l <= r) {
                int m = (l + r) / 2;
                if (queryRange(1,1,n,m,x) <= a[x]) {
                    ans = m;
                    r = m-1;
                } else {
                    l = m+1;
                }
            }
            cnt += x - ans;
            l = x, r = n, ans = x;
            while (l <= r) {
                int m = (l + r) / 2;
                if (queryRange(1,1,n,x,m) <= a[x]) {
                    ans = m;
                    l = m+1;
                } else {
                    r = m-1;
                }
            }
            cnt += ans - x;
            cout << cnt + 1 << '\n';
        } else if (type == 2) {
            int i,x;
            cin >> i >> x;
            updateRange(1,1,n,i,i,x - a[i]);
            a[i] = x;
        } else {
            int i,j,x;
            cin >> i >> j >> x;
            for (int k=i;k<=j;k++) {
                updateRange(1,1,n,k,k,x-a[k]);
                a[k] = x;
            }
        }
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}