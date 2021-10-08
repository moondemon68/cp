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
    ifstream cin("travel_restrictions_input.txt");
    ofstream cout("travel_restrictions_output.txt");
    int tc;
    cin >> tc;
    for (int t=1;t<=tc;t++) {
        int n;
        cin >> n;
        bool ans[n+5][n+5];
        memset(ans,0,sizeof(ans));
        bool in[n+5];
        memset (in,0,sizeof(in));
        string s;
        cin >> s;
        for (int i=1;i<=n;i++) {
            in[i] = (s[i-1] == 'Y');
        }
        bool out[n+5];
        memset (out,0,sizeof(out));
        cin >> s;
        for (int i=1;i<=n;i++) {
            out[i] = (s[i-1] == 'Y');
        }
        vector<int> adj[n+5];
        for (int i=1;i<=n;i++) {
            for (int j=1;j<=n;j++) {
                if (in[j] && out[i] && abs(i-j) == 1) adj[i].pb(j);
            }
        }

        for (int i=1;i<=n;i++) {
            bool vis[n+5];
            memset (vis,0,sizeof(vis));
            stack<int> s;
            s.push(i);
            vis[i] = 1;
            while (!s.empty()) {
                int cur = s.top();
                s.pop();
                for (auto next : adj[cur]) {
                    if (vis[next]) continue;
                    vis[next] = 1;
                    s.push(next);
                }
            }
            for (int j=1;j<=n;j++) {
                ans[i][j] = vis[j];
            }
        }
        
        cout << "Case #" << t << ": " << endl;
        for (int i=1;i<=n;i++) {
            for (int j=1;j<=n;j++) {
                if (ans[i][j]) cout << 'Y';
                else cout << 'N';
            }
            cout << endl;
        }
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}