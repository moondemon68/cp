#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define INF 1234567890
#define pii pair<LL,LL>
#define LL long long
using namespace std;

vector<pii> adj[100005];
LL vis[100005];
LL diam[100005];
vector<LL> ans;
LL start, fin;
vector<LL> finish;

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    LL n;
    cin >> n;
    LL len = 0;
    map<pii, LL> m;
    for (LL i=1;i<n;i++) {
        LL x,y,w;
        cin >> x >> y >> w;
        m[{x, y}] = w;
        m[{y, x}] = w;
        adj[x].pb({y, w});
        adj[y].pb({x, w});
        len += 2*w;
    }
    priority_queue<pii, vector<pii>, greater<pii>> s;
    s.push({0, 1});
    for (LL i=1;i<=n;i++) vis[i] = 12345678987654321;
    vis[1] = 0;
    while (!s.empty()) {
        LL cur = s.top().se;
        s.pop();
        for (LL i=0;i<adj[cur].size();i++) {
            pii next = adj[cur][i];
            if (vis[cur] + next.se < vis[next.fi]) {
                vis[next.fi] = vis[cur] + next.se;
                s.push({vis[cur] + next.se, next.fi});
            }
        }
    }
    LL maxvis = 0, nod1 = INT_MAX;
    for (LL i=1;i<=n;i++) {
        if (vis[i] > maxvis) {
            maxvis = vis[i];
            nod1 = i;
        }
    }
    for (LL i=1;i<=n;i++) {
        if (vis[i] == maxvis) {
            vis[i] = -1;
        }
    }
    LL maxvis2 = 0, nod2 = INT_MAX;
    for (LL i=1;i<=n;i++) {
        if (vis[i] > maxvis2) {
            maxvis2 = vis[i];
            nod2 = i;
        }
    }
    // cout << maxvis << " " << nod1 << " " << maxvis2 << " " << nod2 << endl;
    // nod1 = paling jauh dari 1
    // nod2 = kedua paling jauh dari 1

    s.push({0, nod1});
    for (LL i=1;i<=n;i++) vis[i] = 12345678987654321;
    vis[nod1] = 0;
    while (!s.empty()) {
        LL cur = s.top().se;
        s.pop();
        for (LL i=0;i<adj[cur].size();i++) {
            pii next = adj[cur][i];
            if (vis[cur] + next.se < vis[next.fi]) {
                vis[next.fi] = vis[cur] + next.se;
                s.push({vis[cur] + next.se, next.fi});
            }
        }
    }
    LL maxvis11 = 0, nod11 = INT_MAX, maxvis12 = 0, nod12 = INT_MAX;
    for (LL i=1;i<=n;i++) {
        if (vis[i] > maxvis11) {
            maxvis11 = vis[i];
            nod11 = i;
        }
    }
    for (LL i=1;i<=n;i++) {
        if (vis[i] == maxvis11) {
            vis[i] = -1;
        }
    }
    for (LL i=1;i<=n;i++) {
        if (vis[i] > maxvis12) {
            maxvis12 = vis[i];
            nod12 = i;
        }
    }
    // cout << nod1 << " -> " << maxvis11 << " " << nod11 << " : " << maxvis12 << " " << nod12 << endl;

    // LALLALALAL

    s.push({0, nod2});
    for (LL i=1;i<=n;i++) vis[i] = 12345678987654321;
    vis[nod2] = 0;
    while (!s.empty()) {
        LL cur = s.top().se;
        s.pop();
        for (LL i=0;i<adj[cur].size();i++) {
            pii next = adj[cur][i];
            if (vis[cur] + next.se < vis[next.fi]) {
                vis[next.fi] = vis[cur] + next.se;
                s.push({vis[cur] + next.se, next.fi});
            }
        }
    }
    LL maxvis21 = 0, nod21 = INT_MAX, maxvis22 = 0, nod22 = INT_MAX;
    for (LL i=1;i<=n;i++) {
        if (vis[i] > maxvis21) {
            maxvis21 = vis[i];
            nod21 = i;
        }
    }
    for (LL i=1;i<=n;i++) {
        if (vis[i] == maxvis21) {
            vis[i] = -1;
        }
    }
    for (LL i=1;i<=n;i++) {
        if (vis[i] > maxvis22) {
            maxvis22 = vis[i];
            nod22 = i;
        }
    }
    // cout << nod2 << " -> " << maxvis21 << " " << nod21 << " : " << maxvis22 << " " << nod22 << endl;

    vector<LL> v;
    v.pb(maxvis11);
    v.pb(maxvis12);
    v.pb(maxvis21);
    v.pb(maxvis22);
    sort(v.begin(), v.end());
    LL cannot = v.back();
    LL ans = 0;
    for (auto x : v) {
        if (x == cannot) continue;
        ans = max(ans, x);
    }
    cout << ans << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}