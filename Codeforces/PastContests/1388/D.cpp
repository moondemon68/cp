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
    LL a[n+5];
    for (int i=1;i<=n;i++) cin >> a[i];
    vector<int> adj[n+5];
    int indeg[n+5];
    memset (indeg,0,sizeof(indeg));
    for (int i=1;i<=n;i++) {
        int x;
        cin >> x;
        if (x != -1) {
            adj[i].pb(x);
            indeg[x]++;
        }
    }
    stack<int> s;
    for (int i=1;i<=n;i++) {
        if (indeg[i] == 0) s.push(i);
    }
    LL ans = 0;
    vector<int> v,w;
    while (!s.empty()) {
        int cur = s.top();
        s.pop();
        if (a[cur] > 0) {
            ans += a[cur];
            if (!adj[cur].empty()) a[adj[cur][0]] += a[cur];
            v.pb(cur);
        } else {
            ans += a[cur];
            w.pb(cur);
        }
        for (auto next : adj[cur]) {
            indeg[next]--;
            if (indeg[next] == 0) s.push(next);
        }
    }
    vector<int> ansv;
    for (int i=0;i<v.size();i++) ansv.pb(v[i]);
    for (int i=w.size()-1;i>=0;i--) ansv.pb(w[i]);
    cout << ans << endl;
    for (auto x : ansv) cout << x << " ";
    cout << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}