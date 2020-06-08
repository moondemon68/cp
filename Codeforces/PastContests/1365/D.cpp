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

int dx[4] = {1,0,-1,0};
int dy[4] = {0,-1,0,1};

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc;
    cin >> tc;
    while (tc--) {
        int n,m;
        cin >> n >> m;
        char a[n+5][m+5];
        bool adag = 0;
        for (int i=1;i<=n;i++) {
            string s;
            cin >> s;
            for (int j=1;j<=m;j++) {
                a[i][j] = s[j-1];
                if (a[i][j] == 'G') adag = 1;
            }
        }
        if (adag == 0) {
            cout << "Yes" << endl;
            continue;
        }
        int p[n+5][m+5]; // wall
        memset (p,0,sizeof(p));
        for (int i=1;i<=n;i++) {
            for (int j=1;j<=m;j++) {
                if (a[i][j] == '#') p[i][j] = 1;
                else if (a[i][j] == 'B') {
                    if (a[i+1][j] == '.') p[i+1][j] = 1;
                    if (a[i-1][j] == '.') p[i-1][j] = 1;
                    if (a[i][j+1] == '.') p[i][j+1] = 1;
                    if (a[i][j-1] == '.') p[i][j-1] = 1;
                }
                // cout << p[i][j];
            }
            // cout << endl;
        }
        p[n][m] = 0;
        stack<pii> s;
        s.push({n,m});
        bool vis[n+5][m+5];
        memset (vis,0,sizeof(vis));
        while (!s.empty()) {
            pii cur = s.top();
            s.pop();
            for (int i=0;i<4;i++) {
                pii next = {cur.fi+dx[i], cur.se+dy[i]};
                if (next.fi >= 1 && next.fi <= n && next.se >= 1 && next.se <= m && p[next.fi][next.se] == 0 && !vis[next.fi][next.se]) {
                    vis[next.fi][next.se] = 1;
                    s.push(next);
                }
            }
        }
        bool y = 1;
        for (int i=1;i<=n;i++) {
            for (int j=1;j<=m;j++) {
                if (a[i][j] == 'G' && vis[i][j] == 0) y = 0;
                if (a[i][j] == 'B' && vis[i][j] == 1) y = 0;
            }
        }
        if (y) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}