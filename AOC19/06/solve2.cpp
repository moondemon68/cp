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

// 373 HIGH
// 371 HIGH

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ifstream cin("1.in");
    ofstream cout("2.out");
    int n;
    cin >> n;
    map<string, int> m;
    vector<int> adj[5005];
    int start = 0, end = 0;
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
        if (s == "YOU") start = m[s];
        if (s == "SAN") end = m[s];
        if (t == "YOU") start = m[t];
        if (t == "SAN") end = m[t];
        int x = m[s], y = m[t];
        adj[y].pb(x);
        adj[x].pb(y);
    }
    //cout << start << endl << end << endl;
    int ans = 0;
    for (int i=start;i<=start;i++) {
        int vis[5005];
        memset (vis,0,sizeof(vis));
        queue<int> s;
        s.push(i);
        vis[i] = 1;
        while (!s.empty()) {
            //cout << s.front() << endl;
            int cur = s.front();
            s.pop();
            for (int j=0;j<adj[cur].size();j++) {
                int next = adj[cur][j];
                if (vis[next] == 0) {
                    vis[next] = vis[cur] + 1;
                    s.push(next);
                }
            }
        }
        cout << vis[end]-2 << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}