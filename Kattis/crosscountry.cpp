#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define LL long long

using namespace std;

int a[1005][1005];
vector<pii> adj[100005];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,s,e;
    cin >> n >> s >> e;
    s++;e++;
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=n;j++) cin >> a[i][j];
    }
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=n;j++) {
            if (i!=j) adj[i].pb(mp(a[i][j],j));
        }
    }
    priority_queue<pii,vector<pii>,greater<pii>> d;
    int vis[1005];
    for (int i=1;i<=n;i++) vis[i]=INT_MAX;
    vis[s]=0;
    d.push(mp(0,s));
    while (!d.empty()) {
        pii cur=d.top();
        d.pop();
        for (int i=0;i<adj[cur.se].size();i++) {
            pii next=adj[cur.se][i];
            if (vis[cur.se]+next.fi<vis[next.se]) {
                vis[next.se]=vis[cur.se]+next.fi;
                d.push(mp(vis[next.se],next.se));
            }
        }
    }
    cout << vis[e] << endl;
    return 0;
}
