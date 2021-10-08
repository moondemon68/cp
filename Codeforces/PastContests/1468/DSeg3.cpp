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
    LL tc;
    cin >> tc;
    while (tc--) {
      LL n,m,a2,b;
      cin >> n >> m >> a2 >> b;
      memset(a,0,sizeof(a));
      for (LL i=1;i<=m;i++) cin >> a[i];
      sort(a+1,a+m+1);
      build(1,1,m);
      LL d;
      if (a2 < b) d = b - 1;
      else d = n - b;
      LL l = 0, h = min(m, abs(a2-b) - 1), ans = 0;
      LL p = abs(a2-b) - 1;
      LL maxwait = 0;
      LL cnt = 0;
      for (LL i=1;i<=h;i++) {
        if (a2 < b) {
          if (a2 > 1) {
            // a2--;
            // updateRange(1,1,m,1,i,1);
            cnt++;
          }
        } else {
          if (a2 < n) {
            // a2++;
            // updateRange(1,1,m,1,i,1);
            cnt++;
          }
        }
        maxwait = max(cnt - p, 0LL) + queryRange(1,1,m,1,i);
        LL ll = 1, hh = i, anss = 0;
        while (ll <= hh) {
          LL mm = (ll + hh) / 2;
          LL xx = max(cnt - p, 0LL) + queryRange(1,1,m,1,mm);
          if (xx <= d) {
            anss = mm;
            // cout << mm << " " << xx << endl;
            ll = mm + 1;
          } else {
            hh = mm - 1;
          }
        }
        ans = max(ans, anss);
        if (maxwait <= d) ans = max(ans, i);
        updateRange(1,1,m,1,i,1);
      }
      // cout << "d: " << d << endl;
      cout << ans << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}