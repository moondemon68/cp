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
char a[305][305];
int x[4]={1,0,-1,0};
int y[4]={0,-1,0,1};

bool inside(int a,int b) {
  if (a>=1&&a<=r*3&&b>=1&&b<=c*3) return 1;
  else return 0;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> r >> c;
    for (int i=1;i<=r;i++) {
      string s;
      cin >> s;
      for (int j=1;j<=c;j++) {
        char x=s[j-1];
        if (x=='\\') {
          a[3*i-2][3*j-2]='x';
          a[3*i-1][3*j-2]='.';
          a[3*i-2][3*j-1]='.';
          a[3*i-1][3*j-1]='x';
          a[3*i][3*j-1]='.';
          a[3*i-1][3*j]='.';
          a[3*i][3*j]='x';
        } else {
          a[3*i-2][3*j]='x';
          a[3*i-1][3*j]='.';
          a[3*i-2][3*j-1]='.';
          a[3*i-1][3*j-1]='x';
          a[3*i][3*j-1]='.';
          a[3*i-1][3*j-2]='.';
          a[3*i][3*j-2]='x';
        }
      }
    }

    for (int i=1;i<=3*r;i++) {
      for (int j=1;j<=3*c;j++) {
        if (a[i][j]!='x'&&a[i][j]!='.') a[i][j]='.';
        //cout << a[i][j];
      }
      //cout << endl;
    }

    int vis[305][305];
    memset (vis,0,sizeof(vis));
    stack<pii> s;
    int ans=0,anscnt=0;
    for (int i=1;i<=3*r;i++) {
      for (int j=1;j<=3*c;j++) {
        if (a[i][j]=='.'&&vis[i][j]==0) {
          vis[i][j]=1;
          s.push(mp(i,j));
          int num=1;
          bool g=1;
          while (!s.empty()) {
            pii cur=s.top();
            if (cur.fi==1||cur.fi==3*r||cur.se==1||cur.se==3*c) g=0;
            s.pop();
            for (int p=0;p<4;p++) {
              pii next=mp(cur.fi+x[p],cur.se+y[p]);
              if (inside(next.fi,next.se)&&!vis[next.fi][next.se]&&a[next.fi][next.se]=='.') {
                num++;
                vis[next.fi][next.se]=num;
                s.push(next);
              }
            }
          }
          //cout << vis[i][j] << " " << vis[i+1][j-1] << endl;
          if (g&&vis[i+1][j-1]==num) {
            //cout << i << " " << j <<" " << vis[i][j] << " " << vis[i+1][j-1] << endl;
            anscnt++;
            ans=max(ans,num);
          }
        }
      }
    }
    /*
    for (int i=1;i<=3*r;i++) {
      for (int j=1;j<=3*c;j++) {
        if (vis[i][j]<10) cout << " ";
        cout << vis[i][j] << " ";
      }
      cout << endl;
    }
    */
    cout <<anscnt << " " << ans/3 << endl;
    return 0;
}
