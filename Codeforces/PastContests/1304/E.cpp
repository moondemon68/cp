#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define LL long long
using namespace std;

struct LCA {
    vector<int> height, euler, first, segtree;
    vector<bool> visited;
    int n;

    LCA(vector<vector<int>> &adj, int root = 0) {
        n = adj.size();
        height.resize(n);
        first.resize(n);
        euler.reserve(n * 2);
        visited.assign(n, false);
        dfs(adj, root);
        int m = euler.size();
        segtree.resize(m * 4);
        build(1, 0, m - 1);
    }

    void dfs(vector<vector<int>> &adj, int node, int h = 0) {
        visited[node] = true;
        height[node] = h;
        first[node] = euler.size();
        euler.push_back(node);
        for (auto to : adj[node]) {
            if (!visited[to]) {
                dfs(adj, to, h + 1);
                euler.push_back(node);
            }
        }
    }

    void build(int node, int b, int e) {
        if (b == e) {
            segtree[node] = euler[b];
        } else {
            int mid = (b + e) / 2;
            build(node << 1, b, mid);
            build(node << 1 | 1, mid + 1, e);
            int l = segtree[node << 1], r = segtree[node << 1 | 1];
            segtree[node] = (height[l] < height[r]) ? l : r;
        }
    }

    int query(int node, int b, int e, int L, int R) {
        if (b > R || e < L)
            return -1;
        if (b >= L && e <= R)
            return segtree[node];
        int mid = (b + e) >> 1;

        int left = query(node << 1, b, mid, L, R);
        int right = query(node << 1 | 1, mid + 1, e, L, R);
        if (left == -1) return right;
        if (right == -1) return left;
        return height[left] < height[right] ? left : right;
    }

    int lca(int u, int v) {
        int left = first[u], right = first[v];
        if (left > right)
            swap(left, right);
        return query(1, 0, euler.size() - 1, left, right);
    }
};

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector<vector<int>> adj;
    adj.resize(n+5);
    for (int i=1;i<n;i++) {
        int x,y;
        cin >> x >> y;
        x--;
        y--;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    LCA L(adj);
    int q;
    cin >> q;
    while (q--) {
        int x,y,a,b,k;
        cin >> x >> y >> a >> b >> k;
        x--; y--; a--; b--;
        int ab = L.height[a]-L.height[L.lca(a,b)]+L.height[b]-L.height[L.lca(a,b)];
        int ax = L.height[a]-L.height[L.lca(a,x)]+L.height[x]-L.height[L.lca(a,x)];
        int bx = L.height[b]-L.height[L.lca(b,x)]+L.height[x]-L.height[L.lca(b,x)];
        int ay = L.height[a]-L.height[L.lca(a,y)]+L.height[y]-L.height[L.lca(a,y)];
        int by = L.height[b]-L.height[L.lca(b,y)]+L.height[y]-L.height[L.lca(b,y)];
        int ans1 = ax + by + 1; // ax xy yb
        int ans2 = ay + bx + 1; // ay yx xb
        if ((ab%2) != (k%2)) ab = 2e9;
        if ((ans1%2) != (k%2)) ans1 = 2e9;
        if ((ans2%2) != (k%2)) ans2 = 2e9;
        if (min(ab, min(ans1, ans2)) <= k) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}