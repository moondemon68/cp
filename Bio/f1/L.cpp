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
    int n, m;
    cin >> n >> m;
    vector<int> adj[n+5];
    for (int i=1;i<=m;i++) {
        int x,y;
        cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    bool vis[n+5];
    memset(vis,0,sizeof(vis));
    vector<int> ans;
    priority_queue<int, vector<int>, greater<int>> s;
    s.push(1);
    vis[1] = 1;
    while (!s.empty()) {
        int cur = s.top();
        ans.pb(cur);
        s.pop();
        for (auto next : adj[cur]) {
            if (vis[next]) continue;
            s.push(next);
            vis[next] = 1;
        }
    }
    for (auto x : ans) cout << x << " ";
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
/*
5 8
1 2
1 3
1 5
3 4
5 4
2 4
3 5
2 5


*/