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
    int a[n+5];
    for (int i=1;i<=n;i++) cin >> a[i];
    vector<int> adj[n+5], rev[n+5];
    for (int i=1;i<=n;i++) {
        if (i+a[i]<=n) {
            adj[i].pb(i+a[i]);
            rev[i+a[i]].pb(i);
        }
        if (i-a[i]>=1) {
            adj[i].pb(i-a[i]);
            rev[i-a[i]].pb(i);
        }
    }
    bool c[n+5];
    memset (c,0,sizeof(c));
    for (int i=1;i<=n;i++) {
        if (a[i]%2==1) c[i]=1;
    }
    int ans[n+5];
    memset (ans,0,sizeof(ans));
    int vis[n+5];
    memset (vis,-1,sizeof(vis));
    queue<int> q;
    for (int i=1;i<=n;i++) {
        if (!c[i]) {
            q.push(i);
            vis[i]=0;
        }
    }
    while (!q.empty()) {
        int cur=q.front();
        q.pop();
        for (int i=0;i<rev[cur].size();i++) {
            int next=rev[cur][i];
            if (vis[next] == -1) {
                vis[next] = vis[cur]+1;
                q.push(next);
            }
        }
    }
    for (int i=1;i<=n;i++) {
        if (vis[i] != 0) ans[i]=vis[i];
        // cout << vis[i] << " ";
    }
    // cout << endl;

    memset (vis,-1,sizeof(vis));
    for (int i=1;i<=n;i++) {
        if (c[i]) {
            q.push(i);
            vis[i]=0;
        }
    }
    while (!q.empty()) {
        int cur=q.front();
        q.pop();
        for (int i=0;i<rev[cur].size();i++) {
            int next=rev[cur][i];
            if (vis[next] == -1) {
                vis[next] = vis[cur]+1;
                q.push(next);
            }
        }
    }
    for (int i=1;i<=n;i++) {
        if (vis[i] != 0) ans[i]=vis[i];
        // cout << vis[i] << " ";
    }
    // cout << endl;
    for (int i=1;i<=n;i++) {
        cout << ans[i] << " ";
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}