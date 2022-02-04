#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define INF 1234567890
#define pii pair<int, int>
using namespace std;

const int N = 1e5 + 5;
vector<int> adj[2 * N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NUint);
  cout.tie(NUint);
  int tc;
  cin >> tc;
  while (tc--) {
    int n1;
    cin >> n1;
    for (int i = 0; i <= n1; i++) {
      adj[i].clear();
    }
    for (int i = 1; i < n1; i++) {
      int u, v;
      cin >> u >> v;
      adj[u].pb(v);
      adj[v].pb(u);
    }
    int n2;
    cin >> n2;
    for (int i = n1+1; i <= n2; i++) {
      adj[i].clear();
    }
    for (int i = 1; i < n2; i++) {
      int u, v;
      cin >> u >> v;
      u += n1;
      v += n1;
      adj[u].pb(v);
      adj[v].pb(u);
    }

    vector<int> sz(n1 + n2 + 1);

    function<void(vector<int>&, int, int, int)> dfs =
        [&](vector<int>& centroid, int n, int u, int prev) {
          sz[u] = 1;
          bool is_centroid = true;
          for (auto v : adj[u]) {
            if (v != prev) {
              dfs(centroid, n, v, u);
              sz[u] += sz[v];
              if (2 * sz[v] > n) is_centroid = false;
            }
          }
           if (2 * (n - sz[u]) > n) is_centroid = false;
          if (is_centroid) centroid.pb(u);
        };

    vector<int> centroid1, centroid2;
    sz.assign(n1 + n2 + 1, 0);
    dfs(centroid1, n1, 1, -1);
    sz.assign(n1 + n2 + 1, 0);
    dfs(centroid2, n2, n1 + 1, -1);

    int maxNode, maxD;
    function<void(int, int, int)> dfsDia = [&](int u, int d, int p) {
      if (d > maxD) {
        maxNode = u;
        maxD = d;
      }
      for (auto v : adj[u]) {
        if (v != p) {
          dfsDia(v, d + 1, u);
        }
      }
    };
    
    maxNode = maxD = -1;
    dfsDia(1, 0, -1);
    maxD = -1;
    dfsDia(maxNode, 0, -1);
    centroid1.pb(maxNode);
    maxNode = maxD = -1;
    dfsDia(n1+1, 0, -1);
    maxD = -1;
    dfsDia(maxNode, 0, -1);
    centroid2.pb(maxNode);

    vector<pair<int, pii>> arr;
    for (auto u : centroid1) {
      for (auto v : centroid2) {
        adj[u].pb(v);
        adj[v].pb(u);

        maxNode = maxD = -1;

        dfsDia(1, 0, -1);

        maxD = -1;
        dfsDia(maxNode, 0, -1);

        arr.pb({maxD, {u, v - n1}});

        adj[u].pop_back();
        adj[v].pop_back();
      }
    }
    sort(arr.begin(), arr.end());
    cout << arr[0].fi << '\n';
    cout << arr[0].se.fi << ' ' << arr[0].se.se << '\n';

    
  }
  return 0;
}