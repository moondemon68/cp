#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define INF 1234567890
#define pii pair<LL,LL>
#define LL long long
using namespace std;

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    LL n,m;
    cin >> n >> m;
    vector<pii> adj[n+5];
    for (LL i=1;i<=m;i++) {
        LL u,v,w;
        cin >> u >> v >> w;
        adj[u].pb({v,w});
    }
    LL vis[n+5];
    for (LL i=1;i<=n;i++) vis[i]=-1;
    vis[1]=0;
    stack<LL> s;
    s.push(1);
    while (!s.empty()) {
        LL cur=s.top();
        s.pop();
        for (LL i=0;i<adj[cur].size();i++) {
            pii next=adj[cur][i];
            if (vis[next.fi]<vis[cur]+next.se) {
                vis[next.fi]=vis[cur]+next.se;
                s.push(next.fi);
            }
        }
    }
    cout << vis[n] << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}