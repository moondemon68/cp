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

const int n = 500000;
int valueans[n+5];
vector<int> ans[n+5];
vector<int> adj[n+5];
bool vis[n+5];
int value[n+5];

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ifstream cin("answer.csv");
    ofstream cout("fixanswer.csv");
    
    for (int i=1;i<=n;i++) {
        int u, w, v;
        cin >> u >> w >> v;
        value[u] = w;
        if (v == -1) continue;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    memset(vis,0,sizeof(vis));
    for (int i=0;i<n;i++) {
        if (!vis[i]) {
            set<int> g;
            stack<int> s;
            s.push(i);
            g.insert(i);
            vis[i] = 1;
            while (!s.empty()) {
                int cur = s.top();
                s.pop();
                for (auto next : adj[cur]) {
                    if (!vis[next]) {
                        s.push(next);
                        g.insert(next);
                        vis[next] = 1;
                    }
                }
            }
            int sum = 0;
            for (auto x : g) {
                sum += value[x];
            }
            for (auto x : g) {
                for (auto p : g) {
                    ans[x].pb(p);
                }                
                valueans[x] = sum;
            }
        }
    }
    cout << "ticket_id,ticket_trace/contact" << endl;
    for (int i=0;i<n;i++) {
        cout << i << ",\"";
        for (auto x : ans[i]) {
            cout << x;
            if (x != ans[i].back()) cout << '-';
        }
        cout << ", ";
        cout << valueans[i] << "\"" << endl;
    }

    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}