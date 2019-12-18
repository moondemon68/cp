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
    int n,k;
    cin >> n >> k;
    vector<int> adj[n+5];
    for (int i=1;i<n;i++) {
        int x,y;
        cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    int vis[n+5];
    memset (vis,0,sizeof(vis));
    stack<int> s;
    s.push(1);
    vis[1]=1;
    while (!s.empty()) {
        int cur= s.top();
        s.pop();
        for (int i=0;i<adj[cur].size();i++) {
            int next=adj[cur][i];
            if (vis[next]==0) {
                vis[next]=vis[cur]+1;
                s.push(next);
            }
        }
    }
    int maxi=0,maxa=0;
    for (int i=1;i<=n;i++) {
        if (vis[i]>maxa) {
            maxa=vis[i];
            maxi=i;
        }
    }
    s.push(maxi);
    memset (vis,-1,sizeof(vis));
    vis[maxi]=0;
    int root = maxi;
    int par[n+5];
    memset (par,0,sizeof(par));
    // cout << root << endl;
    // return 0;
    par[root]=root;
    while (!s.empty()) {
        int cur= s.top();
        s.pop();
        for (int i=0;i<adj[cur].size();i++) {
            int next=adj[cur][i];
            if (vis[next]==-1) {
                vis[next]=vis[cur]+1;
                par[next]=cur;
                if (vis[next]==k) {
                    int x = next;
                    while (x!=root) {
                        cout << "flip " << par[x] << endl;
                        x = par[x];
                    }
                    cout << "cut" << " " << cur << " " << next << endl;
                    return 0;
                }
                s.push(next);
            }
        }
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}