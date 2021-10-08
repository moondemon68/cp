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

vector<LL> parent, sz;

void make_set(LL v) {
    parent[v] = v;
    sz[v] = 0;
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
    int tc;
    cin >> tc;
    while (tc--) {
        int n,m;
        cin >> n >> m;

        parent.resize(n+5);
        sz.resize(n+5);
        for (int i=1;i<=n;i++) make_set(i);

        int ans = 0;
        for (int i=1;i<=m;i++) {
            int u,v;
            cin >> u >> v;
            if (u != v) {
                if (find_set(u) == find_set(v)) {
                    ans += 2;
                } else {
                    ans++;
                    union_sets(u, v);
                }
            }
        }
        cout << ans << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}