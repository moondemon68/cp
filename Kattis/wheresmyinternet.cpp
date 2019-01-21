#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define LL long long

using namespace std;

int main () {
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
    bool vis[n+5];
    memset (vis,0,sizeof(vis));
    queue<int> q;
    q.push(1);
    vis[1]=1;
    while (!q.empty()) {
        int cur=q.front();
        q.pop();
        for (int i=0;i<adj[cur].size();i++) {
            int next=adj[cur][i];
            if (!vis[next]) {
                vis[next]=1;
                q.push(next);
            }
        }
    }
    bool y=1;
    for (int i=1;i<=n;i++) {
        if (!vis[i]) {
            y=0;
            cout <<  i << " ";
        }
    }
    if (y) cout << "Connected";
    cout << endl;
    return 0;
}
