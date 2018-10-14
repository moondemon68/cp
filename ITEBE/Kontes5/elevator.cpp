#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define LL long long

using namespace std;
int vis[1000005];
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int f,s,e,u,d;
    cin >> f >> s >> e >> u >> d;
    memset (vis,0,sizeof(vis));
    queue<int> t;
    t.push(s);
    vis[s]=1;
    while (!t.empty()) {
      int cur=t.front();
      t.pop();
      int next=cur+u;
      if (next<=f&&vis[next]==0) {
        vis[next]=vis[cur]+1;
        t.push(next);
      }
      next=cur-d;
      if (next>=1&&vis[next]==0) {
        vis[next]=vis[cur]+1;
        t.push(next);
      }
      if (vis[e]!=0) break;
    }
    cout << vis[e]-1 << endl;
    return 0;
}
