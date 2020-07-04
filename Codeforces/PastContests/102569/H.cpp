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
    for (int i=1;i<n;i++) {
        int x,y;
        cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    bool vis[n+5];
    memset (vis,0,sizeof(vis));
    stack<int> s;
    s.push(1);
    int cnt = 0;
    while (!s.empty()) {
        int cur = s.top();
        s.pop();
        bool y = 0;
        for (int i=0;i<adj[cur].size();i++) {
            int next = adj[cur][i];
            if (!vis[next]) {
                y = 1;
                s.push(next);
                vis[next] = 1;
            }
        }
        if (!y) cnt++;
    }
    cout << (cnt+1)/2 << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}