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
    int n,k;
    cin >> n >> k;
    vector<int> adj[n+5];
    map<pii,int> m;
    for (int i=1;i<=k;i++) {
        int x,y;
        cin >> x >> y;
        if (x>y) swap(x,y);
        if (m[mp(x,y)] == 0) {
            m[mp(x,y)] = 1;
            adj[x].pb(y);
            adj[y].pb(x);
        }
    }
    int p=0;
    bool vis[n+5];
    memset (vis,0,sizeof(vis));
    for (int i=1;i<=n;i++) {
        if (!vis[i] && adj[i].size() > 0) {
            vis[i]=1;
            int cnt=1;
            stack<int> s;
            s.push(i);
            while (!s.empty()) {
                int cur=s.top();
                s.pop();
                for (int j=0;j<adj[cur].size();j++) {
                    int next=adj[cur][j];
                    if (vis[next]) continue;
                    vis[next]=1;
                    cnt++;
                    s.push(next);
                }
            }
            p+=cnt-1;
        }
    }
    cout << k-p << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}