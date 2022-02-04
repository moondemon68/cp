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

int a[105][105];
int b[105][105];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

int n, m;
bool free(int x, int y) {
    return x >= 1 && x <= n && y >= 1 && y <= m && b[x][y] == 0;
}

bool valid(int x, int y) {
    return x >= 1 && x <= n && y >= 1 && y <= m;
}

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=m;j++) {
            cin >> a[i][j];
        }
    }
    int ans = 0;
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=m;j++) {
            if (a[i][j] > 0) {
                for (int k=1;k<=n;k++) {
                    for (int l=1;l<=m;l++) {
                        b[k][l] = a[k][l];
                    }
                }
                b[i][j] = 0;
                int cnt = 1;
                // ledakan pertama
                queue<pair<pii, int>> q;
                for (int k=0;k<4;k++) {
                    for (int p=1;p<=a[i][j];p++) {
                        if (valid(i+dx[k]*p, j+dy[k]*p) && b[i+dx[k]*p][j+dy[k]*p] > 0) {
                            if (free(i+dx[k]*(p+1), j+dy[k]*(p+1))) {
                                q.push(mp(mp(i+dx[k]*(p+1), j+dy[k]*(p+1)), b[i+dx[k]*(p)][j+dy[k]*(p)]));
                            } else {
                                q.push(mp(mp(i+dx[k]*p, j+dy[k]*p), b[i+dx[k]*p][j+dy[k]*p]));
                            }
                            b[i+dx[k]*p][j+dy[k]*p] = 0;
                        }
                    }
                }
                // chains
                while (!q.empty()) {
                    pair<pii,int> cur = q.front();
                    cnt++;
                    q.pop();
                    for (int k=0;k<4;k++) {
                        for (int p=1;p<=cur.se;p++) {
                            pii next = {cur.fi.fi+dx[k]*p, cur.fi.se+dy[k]*p};
                            if (valid(next.fi, next.se)) {
                                if (b[next.fi][next.se] > 0) {
                                    if (free(next.fi+dx[k], next.se+dy[k])) {
                                        q.push({{next.fi+dx[k], next.se+dy[k]}, b[next.fi][next.se]});
                                    } else {
                                        q.push(mp(next, b[next.fi][next.se]));
                                    }
                                    b[next.fi][next.se] = 0;
                                }
                            }
                        }
                    }
                }
                ans = max(ans, cnt);
                // cout << cnt << endl;
            }
        }
    }
    cout << ans << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}