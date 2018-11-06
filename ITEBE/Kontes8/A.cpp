#include <bits/stdc++.h>
#define fi first
#define se second
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
    int r,c;
    cin >> r >> c;
    int cost[10][10];
    for (int i=0;i<=9;i++) {
      for (int j=0;j<=9;j++) {
        cin >> cost[i][j];
      }
    }
    int cnt[10];
    memset (cnt,0,sizeof(cnt));
    for (int i=1;i<=r;i++) {
      for (int j=1;j<=c;j++) {
        int x;
        cin >> x;
        if (x!=-1) cnt[x]++;
      }
    }
    vector<pii> adj[10];
    for (int i=0;i<=9;i++) {
      for (int j=0;j<=9;j++) {
        adj[i].pb(mp(cost[i][j],j));
      }
    }
    int v[10];
    for (int i=0;i<=9;i++) {
      int vis[10];
      for (int j=0;j<=9;j++) {
        vis[j]=INT_MAX;
      }
      //cout << "_________" << endl;
      priority_queue<pii,vector<pii>,greater<pii> > pq;
      vis[i]=0;
      pq.push(mp(0,i));
      while(!pq.empty()) {
        pii cur=pq.top();
        //cout << cur.fi << " " << cur.se << endl;
        pq.pop();
        for (int j=0;j<adj[cur.se].size();j++) {
          pii next=adj[cur.se][j];
          //cout << next.fi << " " << next.se << endl;
          if (vis[cur.se]+next.fi<vis[next.se]) {
            //cout << "YAY";
            vis[next.se]=vis[cur.se]+next.fi;
            pq.push(next);
          }
        }
      }
      v[i]=vis[1];
    }
    int ans=0;
    for (int i=0;i<=9;i++) ans+=cnt[i]*v[i];
    cout << ans << endl;
    return 0;
}
