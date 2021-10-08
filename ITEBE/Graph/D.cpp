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
    int n,m;
    cin >> n >> m;
    vector<int> adj[n+5];
    for (int i=1;i<=m;i++) {
        int x,y;
        cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    stack<int> s;
    int vis[n+5];
    memset (vis,-1,sizeof(vis));
    for (int i=1;i<=n;i++) {
        if (vis[i] == -1) {
            s.push(i);
            vis[i] = 0;
            while (!s.empty()) {
                int cur = s.top();
                s.pop();
                for (auto next : adj[cur]) {
                    if (vis[next] != -1 && vis[next] != 1-vis[cur]) {
                        cout << -1 << endl;
                        return 0;
                    }
                    if (vis[next] == -1) {
                        s.push(next);
                        vis[next] = 1-vis[cur];
                    }
                }
            }
        }
    }
    vector<int> a,b;
    for (int i=1;i<=n;i++) {
        if (vis[i] == 0) a.pb(i);
        else b.pb(i);
    }
    cout << a.size() << endl;
    for (auto x : a) cout << x << " ";
    cout << endl;
    cout << b.size() << endl;
    for (auto x : b) cout << x << " ";
    cout << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}