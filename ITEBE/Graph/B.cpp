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

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,x;
    cin >> n >> x;
    int a[n+5];
    memset (a,0,sizeof(a));
    vector<int> adj[n+5];
    for (int i=1;i<n;i++) {
        cin >> a[i];
        a[i] += i;
        adj[i].pb(a[i]);
    }

    stack<int> s;
    s.push(1);
    bool vis[n+5];
    memset (vis,0,sizeof(vis));
    vis[1] = 1;
    while (!s.empty()) {
        int cur = s.top();
        s.pop();
        for (auto next : adj[cur]) {
            if (!vis[next]) {
                vis[next] = 1;
                s.push(next);
            }
        }
    }
    if (vis[x]) cout << "YES" << endl;
    else cout << "NO" << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}