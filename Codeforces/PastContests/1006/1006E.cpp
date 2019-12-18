#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define LL long long
using namespace std;

vector<int> adj[200005];
int n,q;
int cnt=1;
vector<int> p;
int in[200005],out[200005];

void dfs(int x) {
    p.pb(x);
    in[x]=cnt;
    cnt++;
    for (int i=0;i<adj[x].size();i++) {
        dfs(adj[x][i]);
    }
    out[x]=cnt-1;
}

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> q;
    for (int i=2;i<=n;i++) {
        int x;
        cin >> x;
        adj[x].pb(i);
    }
    dfs(1);
    /*
    for (int i=1;i<=n;i++) cout << in[i] << " ";
    cout << endl;
    for (int i=1;i<=n;i++) cout << out[i] << " ";
    cout << endl;
    for (int i=1;i<=n;i++) cout << p[i-1] << " ";
    cout << endl;
    */
    while (q--) {
        int x,y;
        cin >> x >> y;
        int g=in[x]+y-2;
        if (g<0||g>p.size()) cout << -1 << endl;
        else {
            int ans=p[in[x]+y-2];
            if (ans<=n&&in[x]<=in[ans]&&out[x]>=out[ans]) cout << ans << endl;
            else cout << -1 << endl;
        }
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}