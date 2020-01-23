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
    int n;
    cin >> n;
    vector<int> adj[n+5];
    for (int i=1;i<n;i++) {
        int x,y;
        cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    int vis[n+5];
    memset (vis,-1,sizeof(vis));
    queue<int> s;
    s.push(1);
    vis[1]=0;
    while (!s.empty()) {
        int cur = s.front();
        s.pop();
        for (int i=0;i<adj[cur].size();i++) {
            int next = adj[cur][i];
            if (vis[next] == -1) {
                vis[next] = vis[cur]+1;
                s.push(next);
            }
        }
    }
    int a=0,b=0,c=0, path = 0;
    int maxi = 0;
    for (int i=1;i<=n;i++) {
        if (vis[i] > maxi) {
            maxi = vis[i];
            a = i;
        }
    }

    s.push(a);
    memset (vis,-1,sizeof(vis));
    vis[a] = 0;
    queue<int> q;
    int par[n+5];
    memset (par, -1, sizeof(par));
    par[a] = 0;
    while (!s.empty()) {
        int cur = s.front();
        s.pop();
        for (int i=0;i<adj[cur].size();i++) {
            int next = adj[cur][i];
            if (vis[next] == -1) {
                par[next] = cur;
                vis[next] = vis[cur]+1;
                s.push(next);
            }
        }
    }
    maxi = 0;
    for (int i=1;i<=n;i++) {
        if (vis[i] > maxi) {
            maxi = vis[i];
            b = i;
        }
    }
    // cout << vis[b] << endl;
    // cout << a << " " << b << endl;
    path += vis[b];
    memset (vis,-1,sizeof(vis));
    int p = b;
    while (par[p] != -1) {
        q.push(p);
        vis[p] = 0;
        p = par[p];
    }
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int i=0;i<adj[cur].size();i++) {
            int next = adj[cur][i];
            if (vis[next] == -1) {
                vis[next] = vis[cur]+1;
                q.push(next);
            }
        }
    }
    maxi = 0;
    for (int i=1;i<=n;i++) {
        // cout << vis[i] << " ";
        if (vis[i] > maxi) {
            maxi = vis[i];
            c = i;
        }
    }
    if (c == 0) {
        for (int i=1;i<=n;i++) {
            if (a != i && b != i) {
                c = i;
                break;
            }
        }
    }
    cout << path + vis[c] << endl;
    cout << a << " " << b << " " << c << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}