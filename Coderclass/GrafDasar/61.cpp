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
    int n,m;
    cin >> n >> m;
    int p=-1;
    vector<int> adj[n+5];
    for (int i=1;i<=m;i++) {
        int x,y;
        cin >> x >> y;
        p=x;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    int vis[n+5];
    memset (vis,-1,sizeof(vis));
    vis[p]=0;
    stack<int> s;
    s.push(p);
    bool y=1;
    while (!s.empty()) {
        int cur=s.top();
        s.pop();
        for (int i=0;i<adj[cur].size();i++) {
            int next=adj[cur][i];
            if (vis[next]==vis[cur]) {
                y=0;
                break;
            }
            if (vis[next]==-1) {
                vis[next]=1-vis[cur];
                s.push(next);
            }
        }
    }
    if (!y) cout << "TIDAK" << endl;
    else cout << "YA" << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}