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

const LL MAXN = 1e5;
pii a[MAXN + 5];
vector<LL> adj[MAXN + 5];
LL dp[MAXN+5][2];

void solve(LL cur, LL par = -1) {
    dp[cur][0] = 0;
    dp[cur][1] = 0;
    for (auto next : adj[cur]) {
        if (next == par) continue;
        solve(next, cur);
        dp[cur][0] += max(dp[next][0] + abs(a[cur].fi - a[next].fi), dp[next][1] + abs(a[cur].fi - a[next].se));
        dp[cur][1] += max(dp[next][0] + abs(a[cur].se - a[next].fi), dp[next][1] + abs(a[cur].se - a[next].se));
    }
}

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
        for (LL i=1;i<=n;i++) cin >> a[i].fi >> a[i].se;
        for (LL i=1;i<=n;i++) adj[i].clear();
        for (LL i=1;i<n;i++) {
            LL u,v;
            cin >> u >> v;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        memset(dp,0,sizeof(dp));
        solve(1);
        cout << max(dp[1][0], dp[1][1]) << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}