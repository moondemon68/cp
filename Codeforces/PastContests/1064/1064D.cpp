#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define LL long long

using namespace std;
char a[2005][2005];
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m;
    cin >> n >> m;
    int r,c;
    cin >> r >> c;
    int x,y;
    cin >> x >> y;
    for (int i=1;i<=n;i++) {
      string s;
      cin >> s;
      for (int j=1;j<=m;j++) {
        a[i][j]=s[j-1];
      }
    }
    a[r][c]='+';

    queue<pair<pii,pii>> s;
    s.push(mp(mp(r,c),mp(x,y)));
    while (!s.empty()) {
      r=s.front().fi.fi;
      c=s.front().fi.se;
      x=s.front().se.fi;
      y=s.front().se.se;
      //if (r==1&&c==1) cout << s.front().se.fi << s.front().se.se << endl;
      for (int i=r-1;i>=1;i--) {
        if (a[i][c]=='.') {
          a[i][c]='+';
          s.push(mp(mp(i,c),mp(x,y)));
        } else break;
      }
      for (int i=r+1;i<=n;i++) {
        if (a[i][c]=='.') {
          a[i][c]='+';
          s.push(mp(mp(i,c),mp(x,y)));
        } else break;
      }
      int p=0;
      int xx=x;
      while (xx>0) {
        p++;
        if (a[r][c-p]=='.') {
          a[r][c-p]='+';
          xx--;
          s.push(mp(mp(r,c-p),mp(xx,y)));
        } else break;
      }
      p=0;
      int yy=y;
      while (yy>0) {
        p++;
        if (a[r][c+p]=='.') {
          a[r][c+p]='+';
          yy--;
          s.push(mp(mp(r,c+p),mp(x,yy)));
        } else break;
      }
      s.pop();
    }
    int ans=0;
    for (int i=1;i<=n;i++) {
      for (int j=1;j<=m;j++) if (a[i][j]=='+') ans++;
    }
    cout << ans << endl;
    return 0;
}
