#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define LL long long
using namespace std;

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int r,c;
    cin >> r >> c;
    char a[r+5][c+5];
    for (int i=1;i<=r;i++) {
        string s;
        cin >> s;
        for (int j=1;j<=c;j++) {
            a[i][j]=s[j-1];
        }
    }
    stack<pii> s;
    s.push(mp(1,1));
    int vis[r+5][c+5];
    memset (vis,0,sizeof(vis));
    vis[1][1]=1;
    int dx[9]={1,2,-1,1,0,-1,0,1,-1};
    int dy[9]={-1,0,1,0,1,0,-1,1,-1};
    while (!s.empty()) {
        pii cur = s.top();
        s.pop();
        for (int i=0;i<9;i++) {
            pii next = mp(cur.fi+dx[i], cur.se+dy[i]);
            if (vis[next.fi][next.se] != 0 || next.fi < 1 || next.fi > r || next.se < 1 || next.se > c || a[next.fi][next.se] == '#') continue;
            else {
                vis[next.fi][next.se] = vis[cur.fi][cur.se] + 1;
                s.push(next);
            }
        }
    }
    int ans = vis[r][c]-1;
    if (vis[r][c] == 0) ans = INT_MAX;

    int dx2[9]={1,0,-1,1,0,-1,0,1,-1};
    int dy2[9]={-1,2,1,0,1,0,-1,1,-1};
    s.push(mp(1,1));
    memset (vis,0,sizeof(vis));
    vis[1][1]=1;
    while (!s.empty()) {
        pii cur = s.top();
        s.pop();
        for (int i=0;i<9;i++) {
            pii next = mp(cur.fi+dx2[i], cur.se+dy2[i]);
            if (vis[next.fi][next.se] != 0 || next.fi < 1 || next.fi > r || next.se < 1 || next.se > c || a[next.fi][next.se] == '#') continue;
            else {
                vis[next.fi][next.se] = vis[cur.fi][cur.se] + 1;
                s.push(next);
            }
        }
    }
    int ans2 = vis[r][c]-1;
    if (vis[r][c] == 0) ans2 = INT_MAX;
    // for (int i=1;i<=r;i++) {
    //     for (int j=1;j<=c;j++) {
    //         cout << vis[i][j];
    //     }
    //     cout << endl;
    // }
    cout << min(ans, ans2) << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}