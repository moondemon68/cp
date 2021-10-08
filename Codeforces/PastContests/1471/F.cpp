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
    int tc;
    cin >> tc;
    while (tc--) {
        int n,m;
        cin >> n >> m;
        vector<int> adj[n+5];
        for (int i=1;i<=m;i++) {
            int x,y;
            cin >> x >> y;
            adj[x].pb(y);
            adj[y].pb(x);
        }
        int vis[n+5];
        memset (vis,0,sizeof(vis));
        bool waitada[n+5];
        memset(waitada,0,sizeof(waitada));
        stack<int> s;
        vis[1] = 1;
        s.push(1);
        while (!s.empty()) {
            int cur = s.top();
            s.pop();
            for (auto next : adj[cur]) {
                if (!vis[next]) {
                    vis[next] = 1;
                    s.push(next);
                }
            }
        }
        bool y = 1;
        for (int i=1;i<=n;i++) if (!vis[i]) y = 0;
        if (!y) {
            cout << "NO" << endl;
            continue;
        }
        memset(vis,0,sizeof(vis));
        s.push(1);
        stack<int> wait;
        while (!s.empty()) {
            int cur = s.top();
            s.pop();
            vis[cur] = 1;
            // stack<int> tmp;
            for (auto next : adj[cur]) {
                if (vis[next] == 1) vis[cur] = -1;
                // tmp.push(next);
            }
            for (auto next : adj[cur]) {
                if (!vis[next]) s.push(next);
            }
            // bool y = 0;
            // while (!tmp.empty()) {
            //     int curtmp = tmp.top();
            //     tmp.pop();
            //     for (auto next : adj[curtmp]) {
            //         if (!vis[next]) {
            //             if (!y) {
            //                 vis[next] = 1;
            //                 s.push(next);
            //                 y = 1;
            //             } else {
            //                 if (!waitada[next]) {
            //                     waitada[next] = 1;
            //                     wait.push(next);
            //                 }
            //             }
            //         }
            //     }
            // }
            // if (!y) {
            //     while (!wait.empty()) {
            //         int next = wait.top();
            //         wait.pop();
            //         if (vis[next] == 0) {
            //             y = 1;
            //             s.push(next);
            //             break;
            //         }
            //     }
            // }
        }
        cout << "YES" << endl;
        int cnt = 0;
        for (int i=1;i<=n;i++) if (vis[i] == 1) cnt++;
        cout << cnt << endl;
        for (int i=1;i<=n;i++) if (vis[i] == 1) cout << i << " ";
        cout << endl;
        // for (int i=1;i<=n;i++) cout << vis[i] << " ";
        // cout << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
/*
1
6 10
1 2
2 3
2 4
2 5
4 5
4 6
5 6
1 4
1 5
*/