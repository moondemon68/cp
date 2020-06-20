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

int d[100005];
int p[100005];
bool vis[100005];
vector<int> adj[100005];
pair<int,pii> res;
void dfs(int cur, int par) {
    if (par == -1) {
        d[cur] = 0;
    } else {
        d[cur] = d[par] + 1;
    }
    p[cur] = par;
    vis[cur] = 1;
    for (int i=0;i<adj[cur].size();i++) {
        int next = adj[cur][i];
        if (next == par) continue;
        if (vis[next]) {
            if (d[cur] > d[next]) {
                res = min(res, {d[cur]-d[next]+1, {cur, next}});
            }
        } else {
            dfs(next, cur);
        }
    }
}

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m,k;
    cin >> n >> m >> k;
    for (int i=1;i<=m;i++) {
        int x,y;
        cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    if (m == n-1) {
        int c[n+5];
        memset(c,0,sizeof(c));
        stack<int> s;
        s.push(1);
        c[1] = 1;
        while (!s.empty()) {
            int cur = s.top();
            s.pop();
            for (int i=0;i<adj[cur].size();i++) {
                int next = adj[cur][i];
                if (c[next] != 0) continue;
                c[next] = 3 - c[cur];
                s.push(next);
            }
        }
        vector<int> p,q;
        for (int i=1;i<=n;i++) {
            if (c[i] == 1) p.pb(i); else q.pb(i);
        }
        cout << 1 << endl;
        if (p.size() >= (k+1)/2) {
            for (int i=0;i<(k+1)/2;i++) cout << p[i] << " ";
            cout << endl;
        } else {
            for (int i=0;i<(k+1)/2;i++) cout << q[i] << " ";
            cout << endl;
        }
    } else {
        res.fi = 1e9;
        dfs(1, -1);
        vector<int> cycle;
        int cur = res.se.fi;
        cycle.pb(cur);
        while (cur != res.se.se) {
            cur = p[cur];
            cycle.pb(cur);
        }
        if (cycle.size() <= k) {
            cout << 2 << endl;
            cout << cycle.size() << endl;
            for (auto x : cycle) cout << x << " ";
            cout << endl;
        } else {
            cout << 1 << endl;
            bool y = 1;
            int cnt = 0;
            for (auto x : cycle) {
                if (y && cnt < (k+1)/2) {
                    cout << x << " ";
                    cnt++;
                }
                y = !y;
            }
            cout << endl;
        }
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}