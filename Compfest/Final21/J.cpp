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

int dx[8] = {1,1,0,-1,-1,-1,0,1};
int dy[8] = {0,-1,-1,-1,0,1,1,1};

struct tempel {
  int r;
  int c;
  deque<int> previous_moves;
};


int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m;
    cin >> n >> m;
    string a[n+5];
    for (int i=0;i<n;i++) {
        cin >> a[i];
    }
    pii start, end;
    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {
            if (a[i][j] == 'A') {
                start = {i, j};
            } else if (a[i][j] == 'B') {
                end = {i, j};
            }
        }
    }
    int vis[n+5][m+5][9][9][9];
    memset(vis, 0, sizeof(vis));
    queue<tempel> q;
    tempel t;
    t.r = start.fi;
    t.c = start.se;
    t.previous_moves.push_back(8);
    t.previous_moves.push_back(8);
    t.previous_moves.push_back(8);
    q.push(t);
    while (!q.empty()) {
        tempel cur = q.front();
        // cout << cur.r << " " << cur.c << " " << cur.previous_moves[0] << " " << cur.previous_moves[1] << " " << cur.previous_moves[2] << endl;
        q.pop();
        for (int i=0;i<8;i++) {
            tempel next;
            next.r = cur.r + dx[i];
            next.c = cur.c + dy[i];
            if (!(next.r >= 0 && next.r < n && next.c >= 0 && next.c < m)) {
                continue;
            }
            int p0 = cur.previous_moves[0];
            int p1 = cur.previous_moves[1];
            int p2 = cur.previous_moves[2];
            if (i == p0 || i == p1 || i == p2) continue;    // cooldown
            next.previous_moves.push_back(p0);
            next.previous_moves.push_back(p1);
            next.previous_moves.push_back(p2);
            next.previous_moves.pop_front();
            if (vis[next.r][next.c][p1][p2][i] == 0 && a[next.r][next.c] != '#') {
                vis[next.r][next.c][p1][p2][i] = vis[cur.r][cur.c][p0][p1][p2] + 1;
                next.previous_moves.push_back(i);
                q.push(next);
                if (next.r == end.fi && next.c == end.se) {
                    cout << vis[next.r][next.c][p1][p2][i] << endl;
                    return 0;
                }
            }
        }
    }
    cout << -1 << endl;
    
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}