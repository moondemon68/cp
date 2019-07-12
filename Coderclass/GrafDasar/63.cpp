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
    int r,c;
    cin >> r >> c;
    int dx[]={1,0,-1,0};
    int dy[]={0,-1,0,1};
    char a[r+5][c+5];
    for (int i=1;i<=r;i++) {
        string s;
        cin >> s;
        for (int j=1;j<=c;j++) {
            a[i][j]=s[j-1];
        }
    }
    int vis[r+5][c+5];
    memset (vis,0,sizeof(vis));
    vis[1][1]=1;
    queue<pii> q;
    q.push(mp(1,1));
    while (!q.empty()) {
        pii cur=q.front();
        q.pop();
        for (int i=0;i<4;i++) {
            pii next={cur.fi+dx[i],cur.se+dy[i]};
            if (next.fi>=1&&next.fi<=r&&next.se>=1&&next.se<=c&&a[next.fi][next.se]=='.'&&vis[next.fi][next.se]==0) {
                vis[next.fi][next.se]=vis[cur.fi][cur.se]+1;
                q.push(next);
            }
        }
    }
    cout << vis[r][c]-1 << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}