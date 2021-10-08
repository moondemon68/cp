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
    ifstream cin("gold_mine_chapter_1_input.txt");
    ofstream cout("gold_mine_chapter_1_output.txt");
    int tc;
    cin >> tc;
    for (int t=1;t<=tc;t++) {
        int n;
        cin >> n;
        int c[n+5];
        for (int i=0;i<n;i++) cin >> c[i];
        if (n == 1) {
            cout << "Case #" << t << ": " << c[0] << endl;
            continue;
        }
        vector<vector<int>> adj;
        adj.resize(n);
        for (int i=1;i<n;i++) {
            int x,y;
            cin >> x >> y;
            x--; y--;
            adj[x].pb(y);
            adj[y].pb(x);
        }

        LCA lca(adj);

        int ans = 0;

        // kalo pecah di 0, ambil 2 branch max (branch itu sampe dalem) yang lcanya 0
        // kalo pecah di bukan 0, ambil 1 branch max
        if (adj[0].size() > 1) {
            stack<int> s;
            s.push(0);
            int vis[n+5];
            memset(vis,0,sizeof(vis));
            vis[0] = c[0];
            vector<pii> cand;
            while (!s.empty()) {
                int cur = s.top();
                s.pop();
                for (auto next : adj[cur]) {
                    if (vis[next] != 0) continue;
                    vis[next] = vis[cur] + c[next];
                    s.push(next);
                    if (adj[next].size() == 1) {
                        cand.pb({vis[next], next});
                    }
                }
            }
            sort(cand.begin(), cand.end());
            reverse(cand.begin(), cand.end());
            if (cand.size() == 1) {
                ans = cand[0].fi;
            } else {
                for (int i=0;i<cand.size();i++) {
                    for (int j=i+1;j<cand.size();j++) {
                        if (lca.lca(cand[i].se, cand[j].se) == 0) {
                            ans = max(ans, cand[i].fi + cand[j].fi - c[0]);
                        }
                    }
                }
            }
        } else {
            stack<int> s;
            s.push(0);
            int vis[n+5];
            memset(vis,0,sizeof(vis));
            vis[0] = c[0];
            vector<int> cand;
            while (!s.empty()) {
                int cur = s.top();
                s.pop();
                for (auto next : adj[cur]) {
                    if (vis[next] != 0) continue;
                    vis[next] = vis[cur] + c[next];
                    s.push(next);
                    if (adj[next].size() == 1) {
                        cand.pb(vis[next]);
                    }
                }
            }
            sort(cand.begin(), cand.end());
            reverse(cand.begin(), cand.end());
            ans = cand[0];
        }

        cout << "Case #" << t << ": " << ans << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}