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
    int a[n+5];
    for (int i=1;i<=n;i++) cin >> a[i];
    vector<int> adj[n+5];
    
    stack<pii> s;
    for (int i=1;i<=n;i++) {
        while (!s.empty() && s.top().fi > a[i]) s.pop();
        if (!s.empty()) {
            adj[s.top().se].pb(i);
        }
        s.push({a[i], i});
    }
    while (!s.empty()) s.pop();

    for (int i=1;i<=n;i++) {
        while (!s.empty() && s.top().fi < a[i]) s.pop();
        if (!s.empty()) {
            adj[s.top().se].pb(i);
        }
        s.push({a[i], i});
    }
    while (!s.empty()) s.pop();

    for (int i=n;i>=1;i--) {
        while (!s.empty() && s.top().fi > a[i]) s.pop();
        if (!s.empty()) {
            adj[i].pb(s.top().se);
        }
        s.push({a[i], i});
    }
    while (!s.empty()) s.pop();

    for (int i=n;i>=1;i--) {
        while (!s.empty() && s.top().fi < a[i]) s.pop();
        if (!s.empty()) {
            adj[i].pb(s.top().se);
        }
        s.push({a[i], i});
    }
    while (!s.empty()) s.pop();

    queue<int> q;
    q.push(1);
    int vis[n+5];
    memset (vis,-1,sizeof(vis));
    vis[1] = 0;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int i=0;i<adj[cur].size();i++) {
            int next = adj[cur][i];
            if (vis[next] == -1) {
                vis[next] = vis[cur]+1;
                q.push(next);
            }
        }
    }
    cout << vis[n] << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}