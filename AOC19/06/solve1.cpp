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
    ifstream cin("1.in");
    ofstream cout("1.out");
    int n;
    cin >> n;
    map<string, int> m;
    vector<int> adj[5005];
    int cnt = 0;
    for (int i=1;i<=n;i++) {
        string s,t;
        cin >> s >> t;
        if (m[s] == 0) {
            cnt++;
            m[s] = cnt;
        }
        if (m[t] == 0) {
            cnt++;
            m[t] = cnt;
        }
        int x = m[s], y = m[t];
        adj[y].pb(x);
    }
    int ans = 0;
    for (int i=1;i<=cnt;i++) {
        bool vis[5005];
        memset (vis,0,sizeof(vis));
        stack<int> s;
        s.push(i);
        vis[i] = 1;
        while (!s.empty()) {
            int cur = s.top();
            s.pop();
            for (int j=0;j<adj[cur].size();j++) {
                int next = adj[cur][j];
                if (!vis[next]) {
                    vis[next] = 1;
                    s.push(next);
                }
            }
        }
        for (int j=1;j<=cnt;j++) {
            if (vis[j]) ans++;
        }
        ans--;
    }
    cout << ans << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}