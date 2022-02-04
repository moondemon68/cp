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

char a[100][100];
int vis[100][100];
int n, m, k;

int bfs(pii start, pii end){
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    queue<pii> q;
    q.push(start);
    memset(vis,-1,sizeof(vis));
    vis[start.fi][start.se] = 0;
    while (!q.empty()) {
        pii cur = q.front();
        q.pop();
        for (int i=0;i<4;i++) {
            int nx = cur.fi + dx[i];
            int ny = cur.se + dy[i];
            if (nx < 1 || nx > n || ny < 1 || ny > m) continue;
            if (vis[nx][ny] == -1 && a[nx][ny] != '#') {
                vis[nx][ny] = vis[cur.fi][cur.se] + 1;
                q.push({nx, ny});
                if (nx == end.fi && ny == end.se) {
                    break;
                }
            }
        }
        if (vis[end.fi][end.se] != -1) {
            break;
        }
    }
    if (vis[end.fi][end.se] == -1) {
        return 1000000;
    }
    return vis[end.fi][end.se];
}

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m >> k;
    cin.ignore();
    pii start = {0, 0};
    pii end = {0, 0};
    vector<pii> tel;
    for (int i=1;i<=n;i++) {
        string s;
        getline(cin, s);
        for (int j=1;j<=m;j++) {
            a[i][j] = s[j-1];
            if (a[i][j] == 'O') start = {i, j};
            if (a[i][j] == 'X') end = {i, j};
            if (a[i][j] == '*') tel.pb({i, j});
        }
    }
    int ans = bfs(start, end);

    int tmp = bfs(start, tel[0]);
    while (tmp < k) {
        tmp += 2;
    }
    tmp += bfs(tel[1], end);
    tmp++;
    ans = min(ans, tmp);

    tmp = bfs(start, tel[1]);
    while (tmp < k) {
        tmp += 2;
    }
    tmp += bfs(tel[0], end);
    tmp++;
    ans = min(ans, tmp);

    if (ans >= 1000000) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
/*
5 5 2
#####
#* X#
#####
#O *#
#####
5

5 5 2
#####
#* X#
#   #
#O *#
#####
4

5 5 2
#####
#**X#
#####
#O  #
#####
-1
*/