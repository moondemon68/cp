#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define LL long long
using namespace std;

vector<pii> p;
bool vis[200005];
vector<int> adj[200005];

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m;
    cin >> n >> m;
    for (int i=1;i<=m;i++) {
        int x,y;
        cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    int ans=0;
    memset (vis,0,sizeof(vis));
    for (int i=1;i<=n;i++) {
        if (!vis[i]) {
            int mini=i,maxi=i;
            stack<int> s;
            s.push(i);
            vis[i]=1;
            while (!s.empty()) {
                int cur=s.top();
                s.pop();
                for (int j=0;j<adj[cur].size();j++) {
                    int next=adj[cur][j];
                    if (!vis[next]) {
                        vis[next]=1;
                        s.push(next);
                        maxi = max(maxi, next);
                    }
                }
            }
            p.pb(mp(mini, maxi));
        }
    }
    //for (int i=0;i<p.size();i++) cout << p[i].fi << " " << p[i].se << endl;
    int maxi=p[0].se;
    for (int i=1;i<p.size();i++) {
        if (p[i].fi<maxi) {
            ans++;
        }
        maxi=max(maxi,p[i].se);
    }
    cout << ans << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}