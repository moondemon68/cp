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
        int n;
        cin >> n;
        vector<int> adj[n+5];
        for (int i=1;i<=n;i++) {
            int x;
            cin >> x;
            adj[i].pb(x);
            adj[x].pb(i);
        }
        int vis[n+5];
        memset (vis,-1,sizeof(vis));
        for (int i=1;i<=n;i++) {
            if (vis[i]==-1) {
                stack<int> s;
                s.push(i);
                vector<int> p;
                p.pb(i);
                vis[i]=0;
                while(!s.empty()) {
                    int cur=s.top();
                    s.pop();
                    for (int j=0;j<adj[cur].size();j++) {
                        int next=adj[cur][j];
                        if (vis[next]==-1) {
                            vis[next]=0;
                            p.pb(next);
                            s.push(next);
                        }
                    }
                }
                for (int j=0;j<p.size();j++) {
                    vis[p[j]] = p.size();
                }
            }
        }
        for (int i=1;i<=n;i++) cout << vis[i] << " ";
        cout << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}