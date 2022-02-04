// tree
#include <bits/stdc++.h>
#define pb push_back

using namespace std;

vector<int> adj[200005];
int tin[400005];
int tout[400005];
int a[200005];
int cnt = 0;
void dfs(int u, int p = -1) {
    tin[u] = cnt;
    cnt++;
    for (auto next : adj[u]) {
        if (next == p) continue;
        dfs(next, u);
    }
    tout[u] = cnt;
    cnt++;
}

struct Tree {
    typedef int T;
    static constexpr T unit = INT_MIN;
    T f(T a, T b) { return a+b };
    vector<T> s; int n;
    Tree(int n = 0, T def = unit) : s(2 * n, def), n(n) {}
    void update(int pos, T val) {
        for (s[pos += n] = val; pos /= 2;) s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
    }
    T query(int b, int e) {
        T ra = unit, rb = unit;
        for (b += n, e += n; b < e; b /= 2, e /= 2) {
            if (b % 2) ra = f(ra, s[b++]);
            if (e % 2) rb = f(s[--e], rb);
        }
        return f(ra, rb);
    }
}

int main () {
    memset(tin,0,sizeof(tin));
    memset(tout,0,sizeof(tout));
    int n;
    cin >> n;
    for (int i=0;i<n;i++) cin >> a[i];
    for (int i=1;i<n;i++) {
        int u,v;
        cin >> u >> v;
        u--; v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(0);
    for (int i=0;i<n;i++) {
        cout << tin[i] << " " << tout[i] << endl;;
    }
    Tree t(n);
    for (int i=0;i<n;i++) {
        
    }
    int q;
    cin >> q;
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {

        } else {
            cout << ft.query(tout[i] - 1) - ft.query(tin[i] - 1);
        }
    }
    return 0;
}
/*
5
1 -2 -1 2 -3
1 2
1 3
3 4
3 5
3
2 3
1 5 1
2 3
*/