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

const int MAXN = 2000;
int p[MAXN+5][MAXN+5];
bool vis[MAXN+5][MAXN+5];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m, q;
    cin >> n >> m >> q;
    bool y = 0;
    while (q--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        if (a == b && a == 0) {
            cout << 1 << endl;
            continue;
        }
        if (!y) {
            if (n > MAXN || m > MAXN) {
                cout << -1 << endl;
                continue;
            }
            for (int i = 0; i <= n; i++) {
                for (int j = 0; j <= m; j++) {
                    if ((i&j) == 0) p[i][j] = 1;
                    else p[i][j] = 0;
                }
            }
            y = 1;
        }
        memset(vis, 0, sizeof(vis));
        int cnt = 0;
        for (int i = a; i <= c; i++) {
            for (int j = b; j <= d; j++) {
                if (p[i][j] == 1) {
                    if (!vis[i][j]) {
                        vis[i][j] = 1;
                        cnt++;
                        queue<pii> q;
                        q.push({i, j});
                        while (!q.empty()) {
                            pii cur = q.front();
                            q.pop();
                            for (int k = 0; k < 4; k++) {
                                pii next = {cur.fi + dx[k], cur.se + dy[k]};
                                if (next.fi >= a && next.fi <= c && next.se >= b && next.se <= d && !vis[next.fi][next.se] && p[next.fi][next.se] == 1) {
                                    vis[next.fi][next.se] = 1;
                                    q.push(next);
                                }
                            }
                        }
                    }
                }
            }
        }
        cout << cnt << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
/*
12 12 3
1 1 9 8
8 8 11 11
4 3 5 9
*/