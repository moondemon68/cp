#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define pii pair<int, int>
#define pll pair<ll, ll>

const int N = 2e5 + 5;
int n, m;
ll arr[N];
int color[N], child[N], parent[N], idxOnLines[N];
vector<vector<ll>> segtree;
vector<ll> lines[N];

void dfs(int c, int u) {
  color[u] = c;
  lines[c].pb(arr[u]);
  idxOnLines[u] = lines[c].size() - 1;
  if (child[u] != -1) {
    dfs(c, child[u]);
  }
}

void build(vector<ll>& t, vector<ll>& a, int v, int tl, int tr) {
  if (tl == tr) {
    t[v] = a[tl];
  } else {
    int tm = (tl + tr) / 2;
    build(t, a, 2 * v, tl, tm);
    build(t, a, 2 * v + 1, tm + 1, tr);
    t[v] = min(t[2 * v], t[2 * v + 1]);
  }
}

ll query(vector<ll>& t, int v, int tl, int tr, int l, int r) {
  if (l > r) {
    return 1e9;
  }
  if (l <= tl && tr <= r) {
    return t[v];
  }
  // push(v);
  int tm = (tl + tr) / 2;
  return min(query(t, 2 * v, tl, tm, l, min(r, tm)), query(t, 2 * v + 1, tm + 1, tr, max(l, tm + 1), r));
}

void update(vector<ll>& t, int v, int tl, int tr, int pos, int val) {
  if (tl == tr) {
    t[v] = val;
  } else {
    int tm = (tl + tr) / 2;
    if (pos <= tm) {
      update(t, 2 * v, tl, tm, pos, val);
    } else {
      update(t, 2 * v + 1, tm + 1, tr, pos, val);
    }
    t[v] = min(t[2 * v], t[2 * v + 1]);
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
    child[i] = parent[i] = -1;
  }
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    child[u] = v;
    parent[v] = u;
  }

  for (int i = 1; i <= n; i++) {
    color[i] = -1;
  }

  int c = 0;
  for (int i = 1; i <= n; i++) {
    if (parent[i] == -1) {
      lines[c].pb(-69); // force 1 based index
      dfs(c, i);
      c++;
    }
  }
  segtree.resize(c);
  for (int i = 0; i < c; i++) {
    segtree[i].resize(4 * lines[i].size());
    build(segtree[i], lines[i], 1, 1, lines[i].size() - 1);
  }

  for (int i=1;i<=n;i++) {
      cout << color[i] << " ";
  }
  cout << endl;
  for (int i=0;i<4;i++) {
      for (auto x : lines[i]) cout << x << " ";
      cout << endl;
  }
  for (int i=1;i<=n;i++) {
      cout << idxOnLines[i] << " ";
  }
    cout << endl;
  cout << "======" << endl;

  int q;
  cin >> q;
  while (q--) {
    int type;
    cin >> type;
    if (type == 1) {
      int x, y;
      cin >> x >> y;
      update(segtree[color[x]], 1, 1, lines[color[x]].size() - 1, idxOnLines[x], y);
    } else {
      int u, v;
      cin >> u >> v;
      if (color[u] == color[v] && idxOnLines[u] < idxOnLines[v]) {
        cout << 0 << endl;
      } else {
        ll minu =  query(segtree[color[u]], 1, 1, lines[color[u]].size() - 1, idxOnLines[u], lines[color[u]].size() - 1);
        ll minv =  query(segtree[color[v]], 1, 1, lines[color[v]].size() - 1, 1, idxOnLines[v]);
        cout << minu + minv << endl;
      }
    }
  }
  return 0;
}