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
    int n,m;
    cin >> n >> m;
    vector<int> adj[n+5];
    for (int i=1;i<=m;i++) {
        int x,y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    bool vis[n+5];
    memset (vis,0,sizeof(vis));
    for (int i=1;i<=n;i++) {
        sort (adj[i].begin(),adj[i].end());
        //for (int j=0;j<(int)adj[i].size();j++) cout << adj[i][j] << " ";
        //cout << endl;
    }
    vector<int> ans;
    priority_queue<int,vector<int>,greater<int>> s;
    s.push(1);
    vis[1]=1;
    while (!s.empty()) {
        int cur=s.top();
        s.pop();
        ans.push_back(cur);
        for (int i=0;i<(int)adj[cur].size();i++) {
            int next=adj[cur][i];
            if (!vis[next]) {
                vis[next]=1;
                s.push(next);
            }
        }
    }
    for (int i=0;i<(int)ans.size();i++) cout << ans[i] << " ";
    cout << endl;
    return 0;
}