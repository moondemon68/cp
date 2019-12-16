#include <bits/stdc++.h>
#define pii pair<int,int> 
#define fi first
#define se second
#define pb push_back
#define mp make_pair

using namespace std;

int main () {
    int n,m,a,b;
    cin >> n >> m >> a >> b;
    vector<pii> adj[n+5];
    stack<pii> s;
    for (int i=1;i<=m;i++) {
        int x,y,t,c,h;
        cin >> x >> y >> t >> c >> h;
        adj[x].pb(mp(y,i));
        if (x == 1) s.push(mp(y,i));
    }
    int vis[n+5];
    memset (vis,0,sizeof(vis));
    vis[1] = -1;
    int par[m+5];
    par[1]=1;
    while (!s.empty() && vis[n]==0) {
        pii cur = s.top();
        s.pop();
        for (int i=0;i<adj[cur.fi].size();i++) {
            pii next = adj[cur.fi][i];
            if (vis[next.fi]==0) {
                par[next.se] = cur.se;
                vis[next.fi] = next.se;
                s.push(next);
            }
        }
    }
    vector<int> ans;
    int x = vis[n];
    while (x != 1) {
        ans.pb(x);
        x = par[x];
    }
    ans.pb(1);
    for (int i=ans.size()-1;i>=0;i--) cout << ans[i] << " ";
    return 0;
}