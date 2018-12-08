#include <bits/stdc++.h>
#define dir first
#define fi second.first
#define se second.second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define LL long long

using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc;
    cin >> tc;
    while (tc--) {
      char a[205][205];
      for (int i=1;i<=200;i++) {
        for (int j=1;j<=200;j++) {
          a[i][j]='#';
        }
      }
      int x=2,y=2;
      a[x][y]='.';
      stack<pair<int,pii>> s;
      s.push(mp(-1,mp(x,y)));
      while (!s.empty()) {
        pair<int,pii> cur=s.top();
        s.pop();
        if (cur.dir==0) cout << "N" << endl;
        else if (cur.dir==1) cout << "E" << endl;
        else if (cur.dir==2) cout << "S" << endl;
        else if (cur.dir==3) cout << "W" << endl;
        string reply;
        cin >> reply;
        for (int i=0;i<reply.size();i++) {
          pair<int,pii> next=cur;
          if (reply[i]=='N') {
            next.se++;
            next.dir=0;
            if (a[next.fi][next.se]=='#') {
              a[next.fi][next.se]='.';
              s.push(next);
            }
          }
          else if (reply[i]=='S') {
            next.se--;
            next.dir=2;
            if (a[next.fi][next.se]=='#') {
              a[next.fi][next.se]='.';
              s.push(next);
            }
          }
          else if (reply[i]=='E') {
            next.fi++;
            next.dir=1;
            if (a[next.fi][next.se]=='#') {
              a[next.fi][next.se]='.';
              s.push(next);
            }
          }
          else if (reply[i]=='W') {
            next.fi--;
            next.dir=3;
            if (a[next.fi][next.se]=='#') {
              a[next.fi][next.se]='.';
              s.push(next);
            }
          }
        }
      }
      for (int i=1;i<=3;i++) {
        for (int j=1;j<=3;j++) cout << a[i][j];
        cout << endl;
      }
    }
    return 0;
}
