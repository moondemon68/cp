#include <bits/stdc++.h>
#define fi first.first
#define se first.second
#define num second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define LL long long

using namespace std;

int n,m;
int x[8]={1,1,0,-1,-1,-1,0,1};
int y[8]={0,-1,-1,-1,0,1,1,1};

bool inside(int a,int b) {
  if (a>=1&&a<=n&&b>=1&&b<=m) return 1;
  else return 0;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    char a[105][105];
    for (int i=1;i<=n;i++) {
      string s;
      cin >> s;
      for (int j=1;j<=m;j++) {
        a[i][j]=s[j-1];
      }
    }
    queue<pair<pii,int>> q;
    for (int i=1;i<=n;i++) {
      for (int j=1;j<=m;j++) {
        if (a[i][j]=='B') q.push(mp(mp(i,j),1));
      }
    }
    int ans=0;
    while (!q.empty()) {
      pair<pii,int> cur=mp(mp(q.front().fi,q.front().se),q.front().num);
      q.pop();
      for (int i=0;i<8;i++) {
        int nx=cur.fi+x[i],ny=cur.se+y[i];
        if (inside(nx,ny)) {
          if (cur.num==1&&a[nx][ny]=='A') {
            q.push(mp(mp(nx,ny),2));
          }
          else if (cur.num==2&&a[nx][ny]=='N') {
            q.push(mp(mp(nx,ny),3));
          }
          else if (cur.num==3&&a[nx][ny]=='A') {
            q.push(mp(mp(nx,ny),4));
          }
          else if (cur.num==4&&a[nx][ny]=='N') {
            q.push(mp(mp(nx,ny),5));
          }
          else if (cur.num==5&&a[nx][ny]=='A') {
            ans++;
          }
        }
      }
    }
    cout << ans << endl;
    return 0;
}
