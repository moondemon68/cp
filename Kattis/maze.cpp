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
    int n;
    cin >> n;
    int vis[n+5];
    memset (vis,0,sizeof(vis));
    vector<int> adj[n+5];
    for (int i=1;i<=n;i++) {
        int x;
        cin >> x;
        for (int j=1;j<=x;j++) {
            int y;
            cin >> y;
            adj[i].pb(y);
        }
    }
    vector<pair<vector<int>,int>> v;
    for (int i=1;i<=n;i++) {
        if (vis[i]) continue;
        stack<int> s;
        s.push(i);
        vis[i]=i;
        vector<int> sizes;
        while (!s.empty()) {
            int cur=s.top();
            s.pop();
            sizes.pb(adj[cur].size());
            for (int j=0;j<adj[cur].size();j++) {
                int next=adj[cur][j];
                if (vis[next]) continue;
                vis[next]=i;
                s.push(next);
            }
        }
        sort (sizes.begin(),sizes.end());
        v.pb(mp(sizes,i));
    }
    sort(v.begin(),v.end());
    v.pb(mp({-1},-1));
    vector<int> cans;
    vector<vector<int>> ans;
    for (int i=0;i<v.size();i++) {
        if (v[i].fi==v[i+1].fi) {
            
        }
    }
    return 0;
}