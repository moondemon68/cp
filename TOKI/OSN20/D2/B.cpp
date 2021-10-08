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

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    int xs, ys, xf, yf;
    cin >> xs >> ys >> xf >> yf;
    vector<pair<pii,pii>> v;
    v.pb({{xs, ys}, {0, 0}});
    for (int i=1;i<=n;i++) {
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        v.pb({{a, b}, {c, d}});
    }
    v.pb({{xf, yf}, {0, 0}});
    vector<int> adj[n+5];
    for (int i=0;i<=n+1;i++) {
        for (int j=0;j<=n+1;j++) {
            bool kena = 0;
            if (i == j) kena = 1;

            // hor
            int xp = v[i].fi.fi;
            int yp = v[i].fi.se;
            int w = v[i].se.fi;

            for (int k=xp-w;k<=xp+w;k++) {
                int x1 = k;
                int d = abs(v[j].fi.fi-x1);
                if (d * d <= v[j].se.fi * v[j].se.fi) {
                    kena = 1;
                    break;
                }
            }
            for (int k=yp-w;k<=yp+w;k++) {
                int x1 = k;
                int d = abs(v[j].fi.se-x1);
                if (d * d <= v[j].se.fi * v[j].se.fi) {
                    kena = 1;
                    break;
                }
            }
            if (kena) {
                adj[i].pb(j);
                adj[j].pb(i);
            }
        }
    }

    stack<int> s;
    s.push(0);
    bool vis[n+5];
    memset (vis,0,sizeof(vis));
    while (!s.empty()) {
        int cur = s.top();
        s.pop();
        for (auto x : adj[cur]) {
            if (vis[x]) continue;
            vis[x] = 1;
            s.push(x);
        }
    }
    // if (vis[n+1]) cout << 0 << endl;
    cout << -1 << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}