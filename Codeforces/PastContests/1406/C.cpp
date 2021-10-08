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

vector<vector<int>> adj;

vector<int> Centroid(const vector<vector<int>> &g) {
    int n = g.size();
    vector<int> centroid;
    vector<int> sz(n);
    function<void (int, int)> dfs = [&](int u, int prev) {
        sz[u] = 1;
        bool is_centroid = true;
        for (auto v : g[u]) if (v != prev) {
                dfs(v, u);
                sz[u] += sz[v];
                if (sz[v] > n / 2) is_centroid = false;
        }
        if (n - sz[u] > n / 2) is_centroid = false;
        if (is_centroid) centroid.push_back(u);
    };
    dfs(0, -1);
    return centroid;
}

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc;
    cin >> tc;

    while (tc--) {
        int n;
        cin >> n;
        
        adj.resize(n);
        for (int i=0;i<n;i++) adj[i].clear();
        pii anyedge = {0,0};

        for (int i=1;i<n;i++) {
            int x,y;
            cin >> x >> y;
            anyedge = {x,y};
            x--;
            y--;
            adj[x].pb(y);
            adj[y].pb(x);
        }
        vector<int> centroid = Centroid(adj);

        for (auto cen : centroid) cout << cen << " ";
        cout << endl;
        if (centroid.size() == 1) {
            cout << anyedge.fi << " " << anyedge.se << endl;
            cout << anyedge.fi << " " << anyedge.se << endl;
        } else {
            anyedge.fi = centroid[0];
            for (auto x : adj[centroid[1]]) {
                if (x != centroid[0]) anyedge.se = x;
            }
            cout << centroid[1]+1 << " " << anyedge.se+1 << endl;
            cout << anyedge.fi+1 << " " << anyedge.se+1 << endl;
        }
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}