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
    char a[n+5][m+5];
    for (int i=1;i<=n;i++) {
        string s;
        cin >> s;
        for (int j=1;j<=m;j++) {
            a[i][j] = s[j-1];
        }
    }
    bool y = 1;
    int p = 0, q = 0;
    for (int i=1;i<=n;i++) {
        int cnt = 0;
        if (a[i][1] == '#') cnt = 1;
        for (int j=1;j<m;j++) {
            if (a[i][j] != a[i][j+1]) cnt++;
        }
        if (cnt > 2) y = 0;
        if (cnt == 0) p = 1;
    }
    if (!y) {
        cout << -1 << endl;
        return 0;
    }
    for (int i=1;i<=m;i++) {
        int cnt = 0;
        if (a[1][i] == '#') cnt = 1;
        for (int j=1;j<n;j++) {
            if (a[j][i] != a[j+1][i]) cnt++;
        }
        if (cnt > 2) y = 0;
        if (cnt == 0) q = 1;
    }
    if (!y) {
        cout << -1 << endl;
        return 0;
    }
    if (p != q) {
        cout << -1 << endl;
        return 0;
    }

    int ans = 0;
    bool vis[n+5][m+5];
    int dx[] = {0,-1,0,1};
    int dy[] = {1,0,-1,0};
    memset (vis,0,sizeof(vis));
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=m;j++) {
            if (a[i][j] == '#' && !vis[i][j]) {
                ans++;
                vis[i][j] = 1;
                stack<pii> s;
                s.push({i,j});
                while (!s.empty()) {
                    pii cur = s.top();
                    s.pop();
                    for (int k=0;k<4;k++) {
                        pii next = {cur.fi+dx[k], cur.se+dy[k]};
                        if (next.fi >= 1 && next.fi <= n && next.se >= 1 && next.se <= m && !vis[next.fi][next.se] && a[next.fi][next.se] == '#') {
                            vis[next.fi][next.se] = 1;
                            s.push(next);
                        }
                    }
                }
            }
        }
    }
    cout << ans << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}