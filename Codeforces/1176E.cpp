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
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc;
    cin >> tc;
    while (tc--) {
        int n,m;
        cin >> n >> m;
        int vis[n+5];
        vector<int> adj[n+5];
        memset (vis,0,sizeof(vis));
        for (int i=1;i<=m;i++) {
            int x,y;
            cin >> x >> y;
            adj[x].pb(y);
            adj[y].pb(x);
        }
        vis[1]=1;
        queue<int> q;
        q.push(1);
        while (!q.empty()) {
            int cur=q.front();
            q.pop();
            for (int i=0;i<adj[cur].size();i++) {
                int next=adj[cur][i];
                if (vis[next]!=0) continue;
                vis[next]=vis[cur]+1;
                q.push(next); 
            }
        }
        int p=0;
        for (int i=1;i<=n;i++) if (vis[i]%2==0) p++;
        if (p<=n/2) {
            cout << p << endl;
            for (int i=1;i<=n;i++) if (vis[i]%2==0) cout << i << " ";
        } else {
            cout << n-p << endl;
            for (int i=1;i<=n;i++) if (vis[i]%2==1) cout << i << " ";
        }
        cout << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}