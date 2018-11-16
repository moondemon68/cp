#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define LL long long

using namespace std;

int r,c;
bool inside(int a,int b) {
  return a>=1&&a<=r&&b>=1&&b<=c;
}

int mx[]={1,0,-1,0};
int my[]={0,-1,0,1};
pii v[1005][1005];
int a[1005][1005];
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> r >> c;
    for (int i=1;i<=r;i++) {
      string s;
      cin >> s;
      for (int j=1;j<=c;j++) {
        a[i][j]=s[j-1]-'0';
      }
    }
    for (int i=1;i<=r;i++) {
      for (int j=1;j<=c;j++) {
        v[i][j]=mp(-1,-1);
      }
    }
    for (int i=1;i<=r;i++) {
      for (int j=1;j<=c;j++) {
        if (v[i][j].fi!=-1) continue;
        stack<pii> s;
        s.push(mp(i,j));
        v[i][j]=mp(i,j);
        while (!s.empty()) {
          pii cur=s.top();
          s.pop();
          for (int p=0;p<4;p++) {
            pii next=mp(cur.fi+mx[p],cur.se+my[p]);
            if (inside(next.fi,next.se)&&v[next.fi][next.se].fi==-1&&a[next.fi][next.se]==a[i][j]) {
              v[next.fi][next.se]=mp(i,j);
              s.push(next);
            }
          }
        }
      }
    }
    int q;
    cin >> q;
    for (int i=1;i<=q;i++) {
      int x1,y1,x2,y2;
      cin >> x1 >> y1 >> x2 >> y2;
      if (v[x1][y1]==v[x2][y2]) {
        if (a[x1][y1]==1) cout << "decimal" << endl;
        else cout << "binary" << endl;
      } else {
        cout << "neither" << endl;
      }
    }
    return 0;
}
