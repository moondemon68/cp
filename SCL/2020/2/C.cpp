#include <bits/stdc++.h>
 
using namespace std;
 
#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define forit(i, a) for (__typeof((a).begin()) i = (a).begin(); i != (a).end(); i++)
#define pb push_back
#define mp make_pair
#define sz(a) (int)(a).size()
 
typedef vector <int> vi;
typedef pair <int, int> pii;
 
const int N = (int)5e5;
 
struct edge
{
  int a, b, l, r;
};
typedef vector <edge> List;
 
int cnt[N + 1], ans[N], u[N], color[N], deg[N];
vi g[N];
 
void add( int a, int b )
{
  g[a].pb(b), g[b].pb(a);
}
 
void dfs( int v, int value )
{
  u[v] = 1, color[v] = value;
  forn(i, sz(g[v]))
    if (!u[g[v][i]])
      dfs(g[v][i], value);
}
 
void go( int l, int r, const List &v, int vn, int add_vn ) // [l, r)
{
  if (!sz(v))
  {
    while (l < r)
      ans[l++] = vn + add_vn;
    return;
  }  
 
  List v1;
  forn(i, vn)
    g[i].clear();
  forn(i, sz(v))
    if (v[i].a != v[i].b)
    {
      if (v[i].l <= l && r <= v[i].r)
        add(v[i].a, v[i].b);
      else if (l < v[i].r && v[i].l < r)
        v1.pb(v[i]);
    }
 
  int vn1 = 0;
  forn(i, vn)
    u[i] = 0;
  forn(i, vn)
    if (!u[i])
      deg[vn1] = 0, dfs(i, vn1++);
 
  forn(i, sz(v1))
  {
    v1[i].a = color[v1[i].a];
    v1[i].b = color[v1[i].b];
    if (v1[i].a != v1[i].b)
      deg[v1[i].a]++, deg[v1[i].b]++;
  }
 
  vn = vn1, vn1 = 0;
  forn(i, vn)
    u[i] = vn1, vn1 += (deg[i] > 0), add_vn += !deg[i];
  forn(i, sz(v1))
  {
    v1[i].a = u[v1[i].a];
    v1[i].b = u[v1[i].b];
  }
 
  int m = (l + r) / 2; // [l, m) [m, r)
  go(l, m, v1, vn1, add_vn);
  go(m, r, v1, vn1, add_vn);
}
 
int main()
{
  stack<pii> st;
  map <pii, stack<int>> m;
  List v;
  int n, k;
  cin >> k >> n;
  forn(i, k)
  {
    string type;
    cin >> type;
    if (type == "PUSH" || type == "POP")
    {
      if (type == "PUSH"){
        int a, b;
        cin >> a >> b, a--, b--;
        if (a > b) swap(a, b);
        st.push({a,b});
        m[mp(a, b)].push(i);
      }
      else
      {
          pii top = st.top();
          st.pop();
          int a = top.first, b = top.second;
            int j = m[mp(a, b)].top();
            m[mp(a,b)].pop();
            v.pb({a, b, j, i});
        }
        cnt[i] = 1;
    }
  }
  while (!st.empty()) {
      pii top = st.top();
      st.pop();
          int a = top.first, b = top.second;
        int j = m[mp(a, b)].top();
        m[mp(a,b)].pop();
        v.pb({a, b, j, k});
  }
  go(0, k, v, n, 0);
//   forit(it, v) {
//       cout << it->a << it->b << it->l << it->r << "\n";
//   }
 
  forn(i, k) cout << ans[i] << endl;
  return 0;
}