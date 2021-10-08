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
    LL n;
    cin >> n;
    LL adj[n+5][n+5];
    for (LL i=1;i<=n;i++) {
        for (LL j=1;j<=n;j++) {
            cin >> adj[i][j];
        }
    }
    LL a[n+5];
    for (LL i=1;i<=n;i++) cin >> a[i];

    LL dist[n+5][n+5];
    for (LL i=1;i<=n;i++) {
        for (LL j=1;j<=n;j++) {
            dist[i][j] = adj[i][j];
        }
    }

    LL inside[n+5];
    memset (inside,0,sizeof(inside));
    vector<LL> ans;
    for (LL k=n;k>=1;k--) {
        inside[a[k]] = 1;
        LL sum = 0;
        for (LL i=1;i<=n;i++) {
            for (LL j=1;j<=n;j++) {
                dist[i][j] = min(dist[i][j], dist[i][a[k]] + dist[a[k]][j]);
                if (inside[i] && inside[j]) sum += dist[i][j];
            }
        }
        ans.pb(sum);
    }
    reverse(ans.begin(), ans.end());
    for (auto x : ans) cout << x << " ";
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}