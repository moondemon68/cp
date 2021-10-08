#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define INF 1234567890
#define pii pair<LL,LL>
#define LL long long
using namespace std;
using namespace __gnu_pbds;

#define ordered_set tree<LL, null_type,less<LL>, rb_tree_tag,tree_order_statistics_node_update> 

// all example usages assume that array a is 1-indexed
const LL NMAX = 200000;
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
        t[v] = t[2*v] + t[2*v+1];
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
    t[v] = t[2*v] + t[2*v+1];
}

// queryRange(1,1,n,1,3); --> find sum of a[1..3]
LL queryRange(LL v, LL s, LL e, LL l, LL r){
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
    LL m = (s+e)/2;
    LL p1 = queryRange(2*v, s, m, l, r);
    LL p2 = queryRange(2*v+1, m+1, e, l, r);
    return p1 + p2;
}

// all example usages assume that array a is 1-indexed
LL t2[4*NMAX+3];
LL lazy2[4*NMAX+3];
LL a2[NMAX+3];

// build(1,1,n);
void build2(LL v, LL s, LL e) {
    if (s == e){
        t2[v] = a2[s];
    } else {
        LL m = (s+e)/2;
        build(2*v, s, m);
        build(2*v+1, m+1, e);
        t2[v] = t2[2*v] + t2[2*v+1];
    }
}

// updateRange(1,1,n,1,3,5); --> adds a[1..3] with 5
void updateRange2(LL v, LL s, LL e, LL l, LL r, LL val) {
    if (lazy2[v] != 0){
        t2[v] += lazy2[v];
        if(s != e){
            lazy2[2*v] += lazy2[v];
            lazy2[2*v+1] += lazy2[v];
        }
        lazy2[v] = 0;
    }
    if (s > e || s > r || l > e) {
        return;
    }
    if (l <= s && e <= r) {
        t2[v] += val;
        if(s != e){
            lazy2[2*v] += val;
            lazy2[2*v+1] += val;
        }
        return;
    }
    LL m = (s+e)/2;
    updateRange2(2*v, s, m, l, r, val);
    updateRange2(2*v+1, m+1, e, l, r, val);
    t2[v] = t2[2*v] + t2[2*v+1];
}

// queryRange(1,1,n,1,3); --> find sum of a[1..3]
LL queryRange2(LL v, LL s, LL e, LL l, LL r){
    if (s > e || s > r || l > e) {
        return 0;
    }
    if (lazy2[v] != 0) {
        t2[v] += lazy2[v];
        if (s != e) {
            lazy2[2*v] += lazy2[v];
            lazy2[2*v+1] += lazy2[v];
        }
        lazy2[v] = 0;
    }
    if (l <= s && e <= r) {
        return t2[v];
    }
    LL m = (s+e)/2;
    LL p1 = queryRange2(2*v, s, m, l, r);
    LL p2 = queryRange2(2*v+1, m+1, e, l, r);
    return p1 + p2;
}

ordered_set st;

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    LL n;
    cin >> n;
    vector<pii> query;
    set<LL> s;
    map<LL,LL> m;
    for (LL i=1;i<=n;i++) {
        LL x,y;
        cin >> x >> y;
        query.pb({x,y});
        s.insert(abs(y));
    }
    LL cnt = s.size();
    for (auto x : s) {
        m[x] = cnt;
        cnt--;
    }

    LL sum = 0, dob = 0;
    n = s.size();
    cnt = 0;

    build(1,1,n);
    build2(1,1,n);
    for (pii q : query) {
        LL idx = m[abs(q.se)];
        updateRange(1,1,n,idx,idx,q.se);
        sum += q.se;
        if (q.fi == 0 && q.se > 0) {
            st.insert(q.se);
        } else if (q.fi == 1 && q.se > 0) {
            st.insert(q.se);
            updateRange2(1,1,n,idx,idx,1);
            cnt++;
        } else if (q.fi == 0 && q.se < 0) {
            st.erase(st.find(abs(q.se)));
        } else if (q.fi == 1 && q.se < 0) {
            st.erase(st.find(abs(q.se)));
            updateRange2(1,1,n,idx,idx,-1);
            cnt--;
        }

        if (cnt == 0) {
            cout << sum << endl;
            continue;
        }

        LL topk = *st.find_by_order(st.size()-(cnt-1)-1);
        LL thunder = queryRange2(1,1,n,1,m[topk]);
        if (thunder == cnt && cnt > 0) {
            if (st.end() == st.find_by_order(st.size()-cnt-1)) {
                cout << sum + queryRange(1,1,n,1,m[topk]-1) << endl;
                continue;
            }
            LL nexttopk = *st.find_by_order(st.size()-cnt-1);
            dob = queryRange(1,1,n,1,m[nexttopk]) - topk;
        } else {
            dob = queryRange(1,1,n,1,m[topk]);
        }
        cout << sum+dob << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}