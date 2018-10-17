#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define LL long long

using namespace std;

stack<int> ans;
int vis[30];
bool cycle=0;
vector<int> adj[30];

void toposort(int x) {
  vis[x]=1;
  for (int j=0;j<adj[x].size();j++) {
    if (vis[adj[x][j]]==0) {
      vis[adj[x][j]]=1;
      toposort(adj[x][j]);
    } else if (vis[adj[x][j]]==1) cycle=1;
  }
  ans.push(x);
  vis[x]=2;
}

int main () {
    int n;
    cin >> n;
    char a[105][105];
    for (int i=0;i<=100;i++) {
      for (int j=0;j<=100;j++) {
        a[i][j]='{';
      }
    }
    for (int i=1;i<=n;i++) {
      string s;
      cin >> s;
      for (int j=0;j<s.size();j++) {
        a[i][j+1]=s[j];
      }
    }
    /*
    for (int i=1;i<=n;i++) {
      for (int j=1;j<=10;j++) cout << a[i][j];
      cout << endl;
    }
    */
    for (int p=1;p<=100;p++) {
      for (int i=1;i<n;i++) {
        if (a[i][p]==a[i+1][p]) continue;
        for (int j=i+1;j<=n;j++) {
          //if (a[i][p]==a[j][p]||a[j][p]=='.') continue;
          bool s=1;
          for (int k=1;k<=p;k++) {
            if (a[i][p-k]!=a[j][p-k]) s=0;
          }
          if (s) {
            adj[a[i][p]-'a'+1].pb(a[j][p]-'a'+1);
            break;
          }
        }
      }
    }
    /*
    for (int i=1;i<=26;i++) {
      if (adj[i].size()>0) {
        printf("%c ",i+'a'-1);
        for (int j=0;j<adj[i].size();j++) printf("%c ",adj[i][j]+'a'-1);
        cout << endl;
      }
    }
    */
    memset (vis,0,sizeof(vis));
    for (int i=1;i<=26;i++) {
      if (!vis[i]) toposort(i);
    }
    string answer="";
    while (!ans.empty()) {
      answer+=ans.top()+'a'-1;
      ans.pop();
    }
    if (cycle||answer.size()==27) cout << "Impossible" << endl; else cout << answer << endl;
    return 0;
}
/*
4
dicky
novanto
norman
saviero
3
yonas
adiel
wiguna
3
novanto
wiguna
norman
2
xyz
xy
*/
