#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define INF 1234567890
#define pii pair<LL,LL>
#define LL long long
using namespace std;

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    LL n,m;
    cin >> n >> m;
    LL a[n+5];
    for (LL i=0;i<n;i++) cin >> a[i];
    vector<LL> adj[n+5];
    LL deg[n+5];
    memset (deg,0,sizeof(deg));
    for (LL i=0;i<m;i++) {
        LL x,y;
        cin >> x >> y;
        adj[x].pb(y);
        deg[y]++;
    }

    LL vis[n+5];
    memset (vis,0,sizeof(vis));
    for (LL i=0;i<n;i++) vis[i] = a[i];

    LL ans = 0;
    for (LL i=0;i<n;i++) {
        if (deg[i] == 0) {
            priority_queue<pii> s;
            s.push({vis[i], i});
            while (!s.empty()) {
                pii cur = s.top();
                s.pop();
                for (LL next : adj[cur.se]) {
                    if (vis[cur.se] + a[next] > vis[next]) {
                        vis[next] = vis[cur.se] + a[next];
                        ans = max(vis[next], ans);
                        s.push({vis[next], next});
                    }
                }
            }
        }
    }
    cout << ans << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}