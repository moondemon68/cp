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
    vector<int> adj[100005];
    for (int i=1;i<=m;i++) {
        int x,y;
        cin >> x >> y;
        adj[y].pb(x);
    }
    stack<int> s;
    s.push(1);
    int vis[100005];
    memset (vis,-1,sizeof(vis));
    vis[1]=0;
    while (!s.empty()) {
        int cur=s.top();
        s.pop();
        for (int i=0;i<adj[cur].size();i++) {
            int next=adj[cur][i];
            if (vis[next]==-1||vis[next]==0) {
                vis[next]=vis[cur]+1;
                s.push(next);
            }
        }
    }
    for (int i=1;i<=n;i++) {
        if (vis[i]<=0) cout << 0; else cout << 1;
    }
    return 0;
}
