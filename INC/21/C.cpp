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
    vector<int> adj[n+5];
    int a[n+5], b[n+5];
    for (int i=1;i<=n;i++) cin >> a[i];
    for (int i=1;i<=n;i++) cin >> b[i];
    for (int i=1;i<=n;i++) {
        adj[b[i]].pb(a[i]);
        adj[a[i]].pb(b[i]);
    }
    vector<int> v;
    bool vis[n+5];
    memset(vis,0,sizeof(vis));
    for (int i=1;i<=n;i++) {
        if (vis[i]) continue;
        int cnt = 0;
        vis[i] = 1;
        stack<int> s;
        s.push(i);
        while (!s.empty()) {
            int cur = s.top();
            s.pop();
            cnt++;
            for (auto next : adj[cur]) {
                if (!vis[next]) {
                    vis[next] = 1;
                    s.push(next);
                }
            }
        }
        v.pb(cnt);
    }
    int sum = 0;
    for (auto x : v) {
        if (x == 1 || x == 2 || x == 5) sum++;
    }
    if (sum % 2 == 0) cout << "Second" << endl;
    else cout << "First" << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}