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
    int n,m,k;
    cin >> n >> m >> k;
    vector<int> adj[n+5];
    for (int i=1;i<=m;i++) {
        int x,y;
        cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    map<pii,int> d; //distance
    int f[k+5];
    for (int i=1;i<=k;i++) cin >> f[i];
    sort (f+1,f+k+1);
    f[0]=1;
    for (int p=0;p<=k;p++) {
        int vis[n+5];
        memset (vis,-1,sizeof(vis));
        queue<int> q;
        vis[f[p]]=0;
        q.push(f[p]);
        while (!q.empty()) {
            int cur=q.front();
            q.pop();
            for (int i=0;i<adj[cur].size();i++) {
                int next=adj[cur][i];
                if (vis[next]==-1) {
                    vis[next]=vis[cur]+1;
                    q.push(next);
                }
            }
        }
        for (int l=0;l<=k;l++) {
            d[{f[p],f[l]}]=vis[f[l]];
        }
    }
    /*
    for (int i=0;i<=k;i++) {
        for (int j=0;j<=k;j++) {
            cout << d[{f[i],f[j]}] << " ";
        }
        cout << endl;
    }
    */
    f[k+1]=1;
    int ans=INT_MAX;
    do {
        int t=0;
        for (int i=1;i<=k+1;i++) {
            t+=d[{f[i],f[i-1]}];
        }
        ans=min(ans,t);
    } while (next_permutation(f+1,f+k+1));
    cout << ans << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}