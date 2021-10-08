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

int par[800005];
int vis[800005];
vector<int> adj[800005];
int a[800005];
int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ifstream cin("B_input.txt");
    ofstream cout("B_output.txt");
    int tc;
    cin >> tc;
    for (int t=1;t<=tc;t++) {
        int n;
        cin >> n;
        int ans = 0;
        for (int i=1;i<=n;i++) {
            adj[i].clear();
        }
        map<pii, int> m;
        for (int i=1;i<n;i++) {
            int u,v;
            cin >> u >> v;
            adj[u].pb(v);
            adj[v].pb(u);
            m[{min(u, v), max(u, v)}] = 1;
        }
        map<int,int> cnt;
        set<int> g;
        map<int, vector<int>> p;
        for (int i=1;i<=n;i++) {
            cin >> a[i];
            cnt[a[i]]++;
            p[a[i]].pb(i);
            g.insert(a[i]);
        }

        // for (auto x : g) {    // sorted low to high
        //     int num = x;
        //     if (cnt[num] == 1) continue;
        //     int cur = p[num][0];
        //     for (auto next : adj[cur]) {
        //         if (a[next] == num) {
        //             // cout << next << " " << a[next] << endl;
        //             m[{min(cur, next), max(cur, next)}] = 2;
        //             cnt[num]--;
        //             // cout << cnt[num] << endl;
        //         }
        //     }
        // }
        // set<pii> answer;
        // for (auto x : cnt) {
        //     if (x.se == 1) {
        //         for (auto cur : p[x.fi]) {
        //             for (auto next : adj[cur]) {
        //                 // cout << cur << " " << next << " " << a[cur] << " " << a[next] << endl;
        //                 if (a[cur] != a[next]) answer.insert({min(cur, next), max(cur, next)});
        //             }
        //         }
        //     }
        // }
        // ans = answer.size();
        
        for (int i=1;i<=n;i++) {
            if (i % 1000 == 0) cerr << i << endl;
            if (cnt[a[i]] > 1) {   // ada temen
                stack<int> s;
                memset(par,-1,sizeof(par));
                memset(vis,0,sizeof(vis));
                s.push(i);
                par[i] = i;
                vis[i] = 1;
                while (!s.empty()) {
                    int cur = s.top();
                    s.pop();
                    for (auto next : adj[cur]) {
                        if (vis[next] == 0) {
                            vis[next] = 1;
                            par[next] = cur;
                            s.push(next);
                        }
                    }
                }
                for (int j=1;j<(int)p[a[i]].size();j++) {
                    int cur = p[a[i]][j];
                    while (cur != i) {
                        m[{min(cur, par[cur]), max(cur, par[cur])}] = 2;
                        cur = par[cur];
                    }
                }
            }
        }
        for (auto x : m) {
            if (x.se == 1) ans++;
            // cout << x.fi.fi << " " << x.fi.se << " " << x.se << endl;
        }
        cout << "Case #" << t << ": " << ans << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}