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
#define LL long long
using namespace std;

const int MAXN = 1e5;
LL a[MAXN+5], b[MAXN+5];
set<LL> s;
unordered_map<LL, LL> sum;
unordered_map<LL, LL> parent, sz;

void make_set(LL v) {
    parent[v] = v;
    sz[v] = 1;
}

LL find_set(LL v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(LL a, LL b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (sz[a] < sz[b])
            swap(a, b);
        parent[b] = a;
        sz[a] += sz[b];
    }
}


int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    // init dsu
    for (int i=1;i<=n;i++) cin >> a[i];
    for (int i=1;i<=n;i++) cin >> b[i];
    for (int i=1;i<=n;i++) s.insert(a[i]);
    for (auto x : s) {
        make_set(x);
    }
    vector<LL> tmp;
    for (auto it : s) tmp.pb(it);
    reverse(tmp.begin(), tmp.end());
    for (auto it : tmp) {
        for (auto it2 : s) {
            if ((it^it2) > max(it, it2)) {
                union_sets(it, it2);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        sum[find_set(a[i])] += b[i];
    }
    for (int i = 1; i <= n; i++) {
        if (sz[find_set(a[i])] > 1) {
            cout << sum[find_set(a[i])] << endl;
        } else {
            cout << b[i] << endl;
        }
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}