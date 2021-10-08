#include <bits/stdc++.h>
#define pb push_back

using namespace std;
 
const int N = 2e5 + 5;
int n, m, col[N], cyc_start = 0, cyc_end = 0, par[N];
vector<int> adjList[N];
vector<int> adj[2 * N];
int dp[2 * N];
int cnt[2 * N];
int ans[N];

void dfs(int v){
    col[v] = 1;
    for(auto x : adjList[v]){
        if(col[x] == 0){
            par[x] = v;
            dfs(x);
        } else if(col[x] == 1){
            cyc_end = v;
            cyc_start = x;
        }
    }
    col[v] = 2;
}

bool done[N+5];
void dfs_dp(int u, int p = -1) {
    dp[u] = 1;
    // done[u] = 1;
    int mx = 0;
    for (auto v: adjList[u]) {
        dfs_dp(v);
        mx = max(mx, dp[v]);
    }
    dp[u] = 1 + mx;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n;
    for(int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        adjList[x].push_back(i);
    }

    int cyc[n+5];
    memset(cyc,0,sizeof(cyc));
    int k = n + 1;
    vector<bool> haram(n + 1, false);
    for(int i = 1; i <= n; i++){
        if (col[i] == 0) {
            cyc_start = cyc_end = 0;
            dfs(i);

            if (cyc_start > 0) {
                vector<int> res;
                res.pb(cyc_start);
                cyc[cyc_start] = k;
                int g = cyc_end;
                while (g != cyc_start) {
                    res.pb(g);
                    cyc[g] = k;
                    g = par[g];
                }
                res.pb(g);
                cyc[g] = k;

                for (int x : res) {
                    haram[x] = true;
                    for (int y : adjList[x]) {
                        if (cyc[y] == 0) adjList[k].pb(y);  // must be outside cycle
                    }
                    adjList[x].clear();
                }

                k++;
            }
            
        }
    }

    for (int i = 1; i <= n; i++) {
        if (!haram[i] && ) {
            dfs_dp(i);
            cnt[dp[i]]++;
        }
        for (int j=1;j<=n;j++) {
            cout << dp[j] << " ";
        }
        cout << endl;
    }
    
    // precomp
    for (int i = 1; i <= n; i++) ans[i] = -1;
    ans[n] = 0;
    int cur = n;
    for (int i = 1; i <= n; i++) {
        cur -= cnt[i];
        if (cnt[i] != 0) {
            ans[cur] = i;
        }
    }

    int q;
    cin >> q;
    while (q--) {
        int k;
        cin >> k;
        cout << ans[k] << '\n';
    }
    return 0;
}