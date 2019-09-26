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
    pii a[n+5];
    for (int i=1;i<n;i++) {
        int x,y;
        cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
        a[i].fi=x;
        a[i].se=y;
    }
    int c[n+5];
    for (int i=1;i<=n;i++) cin >> c[i];
    int p=0,q=0;
    for (int i=1;i<n;i++) {
        if (c[a[i].fi] != c[a[i].se]) {
            p=a[i].fi;
            q=a[i].se;
        }
    }
    if (p==0) {
        cout << "YES" << endl;
        cout << 1 << endl;
        return 0;
    }
    stack<int> s;
    s.push(p);
    int vis[n+5];
    memset (vis,-1,sizeof(vis));
    vis[p]=0;
    bool yes=1;
    int col=c[p];
    while (!s.empty()) {
        int cur=s.top();
        s.pop();
        if (vis[cur]==1) col=c[cur];
        else {
            if (c[cur]!=col) yes=0;
        }
        for (int i=0;i<adj[cur].size();i++) {
            int next=adj[cur][i];
            if (vis[next]==-1) {
                vis[next]=vis[cur]+1;
                s.push(next);
            }
        }
    }
    if (yes) {
        cout << "YES" << endl;
        cout << p << endl;
        return 0;
    }

    s.push(q);
    memset (vis,-1,sizeof(vis));
    vis[q]=0;
    yes=1;
    col=c[q];
    while (!s.empty()) {
        int cur=s.top();
        s.pop();
        if (vis[cur]==1) col=c[cur];
        else {
            if (c[cur]!=col) yes=0;
        }
        for (int i=0;i<adj[cur].size();i++) {
            int next=adj[cur][i];
            if (vis[next]==-1) {
                vis[next]=vis[cur]+1;
                s.push(next);
            }
        }
    }
    if (yes) {
        cout << "YES" << endl;
        cout << q << endl;
        return 0;
    }

    cout << "NO" << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}