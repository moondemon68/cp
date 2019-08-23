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
    int n,m;
    cin >> n >> m;
    vector<int> adj[n+5];
    for (int i=1;i<=m;i++) {
        int x,y;
        cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    int p=0;
    int vis[n+5];
    memset (vis,-1,sizeof(vis));
    stack<int> s;
    for (int i=1;i<=n;i++) {
        if (vis[i]==-1) {
            p++;
            vis[i]=p;
            s.push(i);
            while (!s.empty()) {
                int cur=s.top();
                s.pop();
                for (int i=0;i<adj[cur].size();i++) {
                    int next=adj[cur][i];
                    if (vis[next]==-1) {
                        vis[next]=vis[cur];
                        s.push(next);
                    }
                }
            }
        }
    }
    int cnt[n+5];
    memset (cnt,0,sizeof(cnt));
    for (int i=1;i<=n;i++) {
        cnt[vis[i]]++;
    }
    int ans=0;
    for (int i=1;i<=n;i++) {
        ans+=cnt[i]/2;
    }
    cout << ans << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}