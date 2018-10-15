#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define LL long long

using namespace std;

int n,m,ans=0;
char a[105][105];
int x[8]={1,1,0,-1,-1,-1,0,1};
int y[8]={0,-1,-1,-1,0,1,1,1};

bool inside(int a,int b) {
  if (a>=1&&a<=n&&b>=1&&b<=m) return 1;
  else return 0;
}

void dfs(set<pii> s,int cx,int cy) {
  for (int i=0;i<8;i++) {
    pii next=mp(cx+x[i],cy+y[i]);
    if (inside(next.fi,next.se)&&s.count(next)==0) {
      if (s.size()==1&&a[next.fi][next.se]=='A') {
        set<pii> t=s;
        t.insert(mp(next.fi,next.se));
        dfs(t,next.fi,next.se);
      }
      if (s.size()==2&&a[next.fi][next.se]=='N') {
        set<pii> t=s;
        t.insert(mp(next.fi,next.se));
        dfs(t,next.fi,next.se);
      }
      if (s.size()==3&&a[next.fi][next.se]=='A') {
        set<pii> t=s;
        t.insert(mp(next.fi,next.se));
        dfs(t,next.fi,next.se);
      }
      if (s.size()==4&&a[next.fi][next.se]=='N') {
        set<pii> t=s;
        t.insert(mp(next.fi,next.se));
        dfs(t,next.fi,next.se);
      }
      if (s.size()==5&&a[next.fi][next.se]=='A') {
        ans++;
      }
    }
  }
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
      }
    }
    for (int i=1;i<=n;i++) {
      for (int j=1;j<=m;j++) {
        if (a[i][j]=='B') {
          set<pii> s;
          s.insert(mp(i,j));
          dfs(s,i,j);
        }
      }
    }
    cout << ans << endl;
    return 0;
}
