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
    int r1,c1,r2,c2;
    cin >> r1 >> c1 >> r2 >> c2;
    int vis[10][10];
    queue<pii> s;

    // rook
    s.push({r1, c1});
    memset (vis,-1,sizeof(vis));
    vis[r1][c1] = 0;
    while (!s.empty()) {
        pii cur = s.front();
        s.pop();
        for (int i=1;i<=8;i++) {
            for (int j=1;j<=8;j++) {
                if (vis[i][j] == -1 && (i == cur.fi || j == cur.se)) {
                    s.push({i,j});
                    vis[i][j] = vis[cur.fi][cur.se] + 1;
                }
            }
        }
    }
    if (vis[r2][c2] == -1) cout << 0 << " "; else cout << vis[r2][c2] << " ";

    // bishop
    s.push({r1, c1});
    memset (vis,-1,sizeof(vis));
    vis[r1][c1] = 0;
    while (!s.empty()) {
        pii cur = s.front();
        s.pop();
        for (int i=1;i<=8;i++) {
            for (int j=1;j<=8;j++) {
                if (vis[i][j] == -1 && (i + j == cur.fi + cur.se || i - j == cur.fi - cur.se)) {
                    s.push({i,j});
                    vis[i][j] = vis[cur.fi][cur.se] + 1;
                }
            }
        }
    }
    if (vis[r2][c2] == -1) cout << 0 << " "; else cout << vis[r2][c2] << " ";

    // king
    s.push({r1, c1});
    memset (vis,-1,sizeof(vis));
    vis[r1][c1] = 0;
    while (!s.empty()) {
        pii cur = s.front();
        s.pop();
        for (int i=1;i<=8;i++) {
            for (int j=1;j<=8;j++) {
                if (vis[i][j] == -1 && (abs(i-cur.fi) <= 1  && abs(j-cur.se) <= 1)) {
                    s.push({i,j});
                    vis[i][j] = vis[cur.fi][cur.se] + 1;
                }
            }
        }
    }
    if (vis[r2][c2] == -1) cout << 0 << " "; else cout << vis[r2][c2] << " ";

    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}