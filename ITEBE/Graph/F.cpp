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
    string s;
    vector<string> a;
    while (cin >> s) {
        if (s == "#") break;
        a.pb(s);
    }

    bool done[30][30];
    memset (done,0,sizeof(done));
    vector<int> adj[30];
    int deg[30];
    memset (deg,0,sizeof(deg));
    bool ada[30];
    memset (ada,0,sizeof(ada));
    for (int i=0;i<a.size();i++) {
        for (int j=i+1;j<a.size();j++) {
            int k = 0;
            while (k < a[i].size() && k < a[j].size() && a[i][k] == a[j][k]) {
                k++;
            }
            if (k == a[i].size() || k == a[j].size()) continue;
            // cout << a[i][k]-'A' << " " << a[j][k]-'A' << endl;
            if (!done[a[i][k]-'A'][a[j][k]-'A']) {
                adj[a[i][k]-'A'].pb(a[j][k]-'A');
                deg[a[j][k]-'A']++;
                done[a[i][k]-'A'][a[j][k]-'A'] = 1;
                ada[a[i][k]-'A'] = 1;
                ada[a[j][k]-'A'] = 1;
            }
        }
    }

    stack<int> q;
    for (int i=0;i<26;i++) {
        if (deg[i] == 0) q.push(i);
    }

    string ans = "";
    while (!q.empty()) {
        int cur = q.top();
        q.pop();
        if (ada[cur]) ans += (char)(cur+'A');
        for (auto next : adj[cur]) {
            deg[next]--;
            if (deg[next] == 0) q.push(next);
        }
    }
    cout << ans << endl;

    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}