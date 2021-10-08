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
    int n;
    cin >> n;
    vector<int> adj[n+5];
    int dist[n+5][n+5];
    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) dist[i][j] = 69420;
    for (int i=1;i<n;i++) {
        int x,y;
        cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
        dist[x][y] = 1;
    }
    for (int k=1;k<=n;k++) {
        for (int j=1;j<=n;j++) {
            for (int i=1;i<=n;i++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    // for (int i=1;i<=n;i++) {
    //     for (int j=1;j<=n;j++) {
    //         cout << dist[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // return 0;

    vector<int> v;
    for(int i = 1; i <= n; i++){
        v.push_back(i);
    }
    int ans = -1;
    vector<vector<int>> semua;
    do {
        bool y = 1;
        for (int i=0;i<n;i++) {
            if (v[i] == i+1) {
                y = 0;
                break;
            }
        }
        if (!y) continue;

        int cur = 0;
        for (int i=0;i<n;i++) {
            cur += dist[i+1][v[i]];
        }
        if (cur > ans) {
            ans = cur;
            semua.clear();
            semua.pb(v);
        } else if (cur == ans) {
            semua.pb(v);
        }
    } while(next_permutation(v.begin(), v.end()));
    for (int i=0;i<semua.size();i++) {
        cout << i << " ";
        for (auto x : semua[i]) cout << x << " ";
        cout << endl;
    }

    if(n & 1){
        int eigen_factor = 2 * n - 3;
        int cntans = 1;
        for(int i = 1; i <= n + 1; i++){
            cntans *= 2;
        }
        cntans += eigen_factor;
        cout << ans << endl;
        for (auto x : semua[cntans]) cout << x << " ";
        cout << endl;
    } else {
        int g = 1;
        for(int i = 1; i <= n - 1; i++) {
            g *= 2;
        }
        cout << g << '\n';
        cout << ans << " ";
        for (auto x : semua[g]) cout << x << " ";
        cout << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}