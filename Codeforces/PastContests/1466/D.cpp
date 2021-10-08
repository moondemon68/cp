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
    LL tc;
    cin >> tc;
    while (tc--) {
        LL n;
        cin >> n;
        LL a[n+5];
        for (LL i=1;i<=n;i++) cin >> a[i];
        LL deg[n+5];
        memset (deg,0,sizeof(deg));
        vector<LL> adj[n+5];
        for (LL i=1;i<n;i++) {
            LL x,y;
            cin >> x >> y;
            adj[x].pb(y);
            adj[y].pb(x);
            deg[x]++;
            deg[y]++;
        }
        priority_queue<pii> p;
        for (LL i=1;i<=n;i++) {
            if (deg[i] > 1) p.push({a[i], i});
        }
        LL ans = 0;
        for (LL i=1;i<=n;i++) ans += a[i];
        cout << ans << " ";
        while (!p.empty()) {
            pii cur = p.top();
            p.pop();
            ans += cur.fi;
            deg[cur.se]--;
            if (deg[cur.se] > 1) p.push(cur);
            cout << ans << " ";
        }
        cout << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
// 58