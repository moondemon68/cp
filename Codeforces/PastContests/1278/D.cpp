#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define INF 1234567890
#define pii pair<int,int>
#define LL long long
using namespace std;

vector<int> adj[500005];
bool vis[500005];
int n;

bool dfs(int v, int par) {
    vis[v] = 1;
    for (int i=0;i<adj[v].size();i++) {
        int next = adj[v][i];
        if (!vis[next]) {
            dfs(next, v);
        } else if (next != par) return 1;
    }
    return 0;
}
bool isCycle() {
    return dfs(1, -1);
}

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    pii p[n+5];
    for (int i=1;i<=n;i++) cin >> p[i].fi >> p[i].se;
    sort (p+1,p+n+1);
    int cnt=0;
    for (int i=1;i<=n;i++) {
        for (int j=i+1;j<=n;j++) {
            if (p[j].fi > p[i].se) break;
            else {
                if (p[j].se > p[i].se) {
                    cnt++;
                    //cout << i << " " << j << endl;
                    adj[i].pb(j);
                    adj[j].pb(i);
                }
                if (cnt >= n) {
                    cout << "NO" << endl;
                    return 0;
                }
            }
        }
    }
    if (cnt != n-1) {
        cout << "NO" << endl;
        return 0;
    } else {
        memset (vis,0,sizeof(vis));
        if (isCycle()) cout << "NO" << endl;
        else {
            bool y = 1;
            for (int i=1;i<=n;i++) {
                //cout << vis[i] << " ";
                if (!vis[i]) y = 0;
            }
            if (y) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
    }

    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}