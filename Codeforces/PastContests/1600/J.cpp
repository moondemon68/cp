#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define INF 1234567890
#define pii pair<int,int>
#define LL long long
using namespace std;

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m;
    cin >> n >> m;
    int a[n+5][m+5];
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=m;j++) {
            cin >> a[i][j];
        }
    }
    bool vis[n+5][m+5];
    memset(vis,0,sizeof(vis));
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    vector<int> ans;
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=m;j++) {
            if (vis[i][j]) continue;
            stack<pii> s;
            s.push({i, j});
            vis[i][j] = 1;
            int sz = 1;
            while (!s.empty()) {
                pii cur = s.top();
                s.pop();
                for (int k=0;k<4;k++) {
                    pii next = {cur.fi + dx[k], cur.se + dy[k]};
                    if (next.fi >= 1 && next.fi <= n && next.se >= 1 && next.se <= m && !vis[next.fi][next.se] && ((a[cur.fi][cur.se] & (1 << (3-k))) == 0)) {
                        s.push(next);
                        vis[next.fi][next.se] = 1;
                        sz++;
                    }
                }
            }
            ans.pb(sz);
        }
    }
    sort(ans.begin(), ans.end());
    for (int i=ans.size()-1;i>=0;i--) cout << ans[i] << " ";
    cout << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}