#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define LL long long

using namespace std;

int n,m;
int x[4]={1,0,-1,0};
int y[4]={0,-1,0,1};
int vis[1005][1005];
char a[1005][1005];

bool inside(int a,int b) {
  if (a>=1&&a<=n&&b>=1&&b<=m) return 1;
  else return 0;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for (int i=1;i<=n;i++) {
      string s;
      cin >> s;
      for (int j=1;j<=m;j++) {
        a[i][j]=s[j-1];
        vis[i][j]=INT_MAX;
      }
    }
    deque<pii> q;
    vis[1][1]=1;
    //int p=0;
    while (!q.empty()) {
      pii cur=q.front();
      q.pop_front();
      for (int i=0;i<4;i++) {
        int nx=cur.fi+x[i],ny=cur.se+y[i];
        if (inside(nx,ny)) {
          //p++;
          if (a[nx][ny]!=a[cur.fi][cur.se]) {
            if (vis[nx][ny]>vis[cur.fi][cur.se]+1) {
              vis[nx][ny]=vis[cur.fi][cur.se]+1;
              q.push_back(mp(nx,ny));
            }
          }
          else {
            if (vis[nx][ny]>vis[cur.fi][cur.se]) {
              vis[nx][ny]=vis[cur.fi][cur.se];
              q.push_front(mp(nx,ny));
            }
          }
        }
      }
      if (vis[n][m]!=INT_MAX) break;
    }
    //cout << p << endl;
    for (int i=1;i<=n;i++) {
      for (int j=1;j<=m;j++) cout << vis[i][j] << ' ';
      cout << endl;
    }
    cout << vis[n][m]-1 << endl;
    return 0;
}
