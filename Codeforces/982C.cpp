#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define LL long long
using namespace std;

vector<int> adj[100005];
bool vis[100005];
int cnt[100005];

void dfs(int x) {
    cnt[x]=1;
    vis[x]=1;
    for (int i=0;i<adj[x].size();i++) {
        int next=adj[x][i];
        if (vis[next]) continue;
        dfs(next);
        cnt[x]+=cnt[next];
    }
}

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for (int i=1;i<n;i++) {
        int x,y;
        cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    if (n%2==1) {
        cout << -1 << endl;
        return 0;
    }
    memset (vis,0,sizeof(vis));
    memset (cnt,0,sizeof(cnt));
    dfs(1);
    //for (int i=1;i<=n;i++) cout << cnt[i] << " ";
    //cout << endl;
    int ans=0;
    for (int i=1;i<=n;i++) ans+=(cnt[i]%2==0);
    cout << ans-1 << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}