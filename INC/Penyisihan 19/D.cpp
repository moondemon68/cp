#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC optimize(3)
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC target("sse3","sse2","sse")
#pragma GCC target("avx","sse4","sse4.1","sse4.2","ssse3")
#pragma GCC target("f16c")
#pragma GCC optimize("inline","fast-math","unroll-loops","no-stack-protector")
// #pragma GCC diagnostic error "-fwhole-program"
// #pragma GCC diagnostic error "-fcse-skip-blocks"
// #pragma GCC diagnostic error "-funsafe-loop-optimizations"
// #pragma GCC diagnostic error "-std=c++14"
// #pragma GCC target ("string"...)
#pragma GCC push_options
#pragma GCC pop_options
#pragma GCC reset_options
#pragma GCC optimize ("O3")

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n, m, q;
vector<int> g[N];
short int vis[N];
int par[N], sz[N], parz[N];
deque<int> dq;

int fpar(int x) {
    if (par[x] == x) return x;
    return par[x] = fpar(par[x]);
}

bool merge(int u, int v) {
    int pu = fpar(u);
    int pv = fpar(v);
    if (pu == pv) return true;
    if (sz[pu] < sz[pv]) swap(pu, pv);
    sz[pu] += sz[pv];
    par[pv] = pu;
    return false;
}

void dfs(int u, int p) {
    //cerr << u << '\n';
    dq.push_front(u);
    vis[u] = 1;
    for (auto e : g[u]) {
        if (e == p) continue;
        if (vis[e] == 0) {
            dfs(e, u);
        } else if (vis[e] == 1) {
            //cerr << "Cycle founded : " << u << " " << e << "\n";
            for (auto el : dq) {
                if (el == e) break;
                //cerr << "Merged : " << e << " " << el << '\n';
                merge(el, e);
            }
            //cerr << '\n';
        }
    }
    dq.pop_front();
    vis[u] = 2;
}

int main() {

    scanf("%d%d%d",&n,&m,&q);

    for (int i = 1; i <= n; i++) {
        par[i] = i;
        sz[i] = 1;
    }

    for (int i = 1; i <= m; i++) {
        int u, v;
        scanf("%d%d",&u,&v);
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(1,1);

    for (int i = 1; i <= n; i++) {
        parz[i] = fpar(i);
    }

    /*cerr << "--PARENTS--" << '\n';
    for (int i = 1; i <= n; i++) {
        cerr << i << " => " << parz[i] << '\n';
    }*/

    for (int i = 1; i <= q; i++) {
        int u, v;
        scanf("%d%d",&u,&v);
        if (parz[u] == parz[v]) printf("YES\n"); else printf("NO\n");
    }

    return 0;
}