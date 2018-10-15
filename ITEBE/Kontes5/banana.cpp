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
    int vis[105][105];
    memset (vis,-1,sizeof(vis));
    for (int i=1;i<=n;i++) {
      string s;
      cin >> s;
      for (int j=1;j<=m;j++) {
        a[i][j]=s[j-1];
      }
    }

    return 0;
}
