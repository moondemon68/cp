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

vector<int> adj[3005 * 3005 + 5];
int vis[3005*3005 + 5];
int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m;
    cin >> n >> m;
    while (m--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1--; y1--;
        x2--; y2--;
        adj[x1 * n + y1].pb(x2 * n + y2);
        adj[x2 * n + y2].pb(x1 * n + y1);
    }
    memset(vis,-1,sizeof(vis));
    int ans = 0;
    for (int i=0;i<n*n;i++) {
        if (vis[i] != -1) continue;
        stack<int> s;
        s.push(i);
        vis[i] = 1;
        int black = 1, white = 0;
        while (!s.empty()) {
            int cur = s.top();
            s.pop();
            for (auto next : adj[cur]) {
                if (vis[next] == -1) {
                    vis[next] = 1 - vis[cur];
                    if (vis[next] == 1) black++; else white++;
                    s.push(next);
                }
            }
        }
        ans += max(black, white);
    }
    cout << ans << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}