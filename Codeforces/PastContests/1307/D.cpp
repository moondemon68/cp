#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define LL long long
using namespace std;

bool cmp(pii a, pii b) {
    return a.fi-a.se < b.fi-b.se;
}

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m,k;
    cin >> n >> m >> k;
    int a[n+5];
    memset (a,0,sizeof(a));
    for (int i=1;i<=k;i++) {
        int x;
        cin >> x;
        a[x] = i;
    }
    vector<int> adj[n+5];
    for (int i=1;i<=m;i++) {
        int x,y;
        cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    int b[n+5];
    memset (b,-1,sizeof(b));
    b[1] = 0;
    queue<int> q;
    q.push(1);
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int i=0;i<adj[cur].size();i++) {
            int next = adj[cur][i];
            if (b[next] == -1) {
                b[next] = b[cur] + 1;
                q.push(next);
            }
        }
    }

    int c[n+5];
    memset (c,-1,sizeof(c));
    c[n] = 0;
    q.push(n);
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int i=0;i<adj[cur].size();i++) {
            int next = adj[cur][i];
            if (c[next] == -1) {
                c[next] = c[cur] + 1;
                q.push(next);
            }
        }
    }

    // for (int i=1;i<=n;i++) cout << b[i] << " ";
    // cout << endl;
    // for (int i=1;i<=n;i++) cout << c[i] << " ";
    // cout << endl;
    vector<pii> p;
    for (int i=1;i<=n;i++) {
        if (a[i] != 0) p.pb({b[i], c[i]});
    }
    sort (p.begin(), p.end(), cmp);
    // for (int i=0;i<p.size();i++) cout << p[i].fi << " " << p[i].se << endl;
    int x = p.size();
    int s[x+5];
    s[x-1] = p[x-1].se;
    for (int i=x-2;i>=0;i--) {
        s[i] = max(s[i+1], p[i].se);
    }
    int ans = 0;
    for (int i=0;i<p.size()-1;i++) {
        ans = max(ans, p[i].fi + s[i+1] + 1);
    }
    cout << min(ans, b[n]) << endl;

    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}