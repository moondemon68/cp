#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define INF 1234567890
#define pii pair<int,int>
#define LL long long
#define x first.first
#define y first.second
#define d second
using namespace std;

int dx[4] = {0,-1,0,1};
int dy[4] = {1,0,-1,0};

int n,m,k;
bool inside(int ix, int iy) {
    return ix >= 1 && ix <= n && iy >= 1 && iy <= m;
}

bool cmp(pair<pii, int> a, pair<pii, int> b) {
    return a.d > b.d;
}

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m >> k;
    char a[n+5][m+5];
    int sx = -1, sy = -1, ex = -1, ey = -1;
    for (int i=1;i<=n;i++) {
        string s;
        cin >> s;
        for (int j=1;j<=m;j++) {
            a[i][j] = s[j-1];
            if (a[i][j] == 'S') {
                sx = i;
                sy = j;
            } else if (a[i][j] == 'E') {
                ex = i;
                ey = j;
            }
        }
    }
    vector<pair<pii, int>> v;   // (x,y), d
    while (k--) {
        int ix,iy,id;
        cin >> ix >> iy >> id;
        v.pb({{ix, iy}, id});
    }
    bool can[n+5][m+5];
    memset(can,1,sizeof(can));
    sort(v.begin(), v.end(), cmp);

    int bigvis[n+5][m+5];
    memset(bigvis,-1,sizeof(bigvis));

    for (auto b : v) {
        if (bigvis[b.x][b.y] <= b.d && bigvis[b.x][b.y] != -1) continue;
        bigvis[b.x][b.y] = b.d;
        can[b.x][b.y] = 0;
        queue<pair<pii, int>> q;
        q.push({{b.x, b.y}, {b.d}});
        while (!q.empty()) {
            pair<pii,int> cur = q.front();
            q.pop();
            for (int i=0;i<4;i++) {
                pair<pii,int> next = {{cur.x + dx[i], cur.y + dy[i]}, cur.d - 1};
                if (inside(next.x, next.y) && a[next.x][next.y] != '#' && bigvis[next.x][next.y] < next.d) {
                    bigvis[next.x][next.y] = next.d;
                    can[next.x][next.y] = 0;
                    q.push(next);
                }
            }
        }
    }
    int vis[n+5][m+5];
    memset(vis,-1,sizeof(vis));
    vis[sx][sy] = 0;
    queue<pii> q;
    q.push({sx, sy});
    while (!q.empty()) {
        pii cur = q.front();
        q.pop();
        for (int i=0;i<4;i++) {
            pii next = {cur.fi + dx[i], cur.se + dy[i]};
            if (inside(next.fi, next.se) && vis[next.fi][next.se] == -1 && a[next.fi][next.se] != '#' && can[next.fi][next.se]) {
                vis[next.fi][next.se] = vis[cur.fi][cur.se] + 1;
                q.push(next);
            }
        }
    }
    if (vis[ex][ey] == -1 || !can[ex][ey] || !can[sx][sy]) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        cout << vis[ex][ey] << endl;
    }
    // for (int i=1;i<=n;i++) {
    //     for (int j=1;j<=m;j++) {
    //         cout << bigvis[i][j] << "\t";
    //     }
    //     cout << endl;
    // }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}