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
        t[v] = max(t[2*v], t[2*v+1]);
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
    t[v] = max(t[2*v], t[2*v+1]);
}

// queryRange(1,1,n,1,3); --> find min between a[1..3]
LL queryRange(int v, int s, int e, int l, int r){
    if (s > e || s > r || l > e) {
        return INT_MIN;
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
    return max(p1, p2);
}

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc;
    cin >> tc;
    while (tc--) {
        int n,k;
        cin >> n >> k;
        int x[n+5];
        for (int i=1;i<=n;i++) cin >> x[i];
        int y[n+5];
        for (int i=1;i<=n;i++) cin >> y[i];
        sort (x+1,x+n+1);
        for (int i=1;i<=n;i++) {
            int l = i, r = n, ans = i;
            while (l <= r) {
                int m = (l + r)/2;
                if (x[m] > x[i]+k) {
                    r = m-1;
                } else {
                    ans = m;
                    l = m+1;
                }
            }
            a[i] = ans;
        }
        int b[n+5];
        b[0] = -1;
        for (int i=1;i<=n;i++) {
            b[i] = a[i];
            a[i] -= i;
            a[i]++;
        }
        build(1, 1, n);

        // for (int i=1;i<=n;i++) cout << b[i] << " ";
        // cout << endl;
        // brute
        int ans = 0;
        for (int i=1;i<=n;i++) {
            if (b[i] <= b[i-1] + 1) continue;
            int tmp1 = b[i]-i+1;
            
            // updateRange(1,1,n,b[i],n,-b[i]);
            int tmp2 = queryRange(1, 1, n, b[i]+1, n);
            if (b[i]+1 > n) tmp2 = 0;
            // updateRange(1,1,n,b[i],n,b[i]);
            // for (int j=i;j<=n;j++) {
            //     int p = (b[i]-i+1) + (a[j]-j+1) - max(0, b[i]-j+1);
            //     ans = max(ans, p);
            // }
            // cout << i << " " << tmp1 << " " << b[i] << " " << n << " " << tmp2 << endl;
            ans = max(ans, tmp1 + tmp2);
        }

        // yolo ternary (WA euy)
        // for (int i=1;i<=n;i++) {
        //     int l = i, r = n;
        //     int m1 = (l*2 + r) / 3;
        //     int m2 = (l + r*2) / 3;
        //     int x1 = (a[m1]-m1+1) + (a[i]-i+1) - max(0, a[i]-m1+1);
        //     int x2 = (a[m2]-m2+1) + (a[i]-i+1) - max(0, a[i]-m2+1);
        //     ans = max(ans, x1);
        //     ans = max(ans, x2);
        //     if (x1 > x2) {
        //         r = m2;
        //     } else if (x1 < x2) {
        //         l = m1;
        //     } else {
        //         l = m1;
        //         r = m2;
        //     }
        // }

        cout << ans << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}