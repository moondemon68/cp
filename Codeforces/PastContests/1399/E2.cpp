#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define INF 1234567890
#define pii pair<LL,LL>
#define LL long long
using namespace std;

vector<LL> adj[100005];
LL par[100005];
LL sz[100005];
bool vis[100005];

LL dfs(LL x) {
    LL cnt = 0;
    vis[x] = 1;
    if (adj[x].size() == 1) cnt++;
    for (auto next : adj[x]) {
        if (vis[next]) continue;
        par[next] = x;
        cnt += dfs(next);
    }
    return sz[x] = cnt;
}

struct CustomCompare
{
    bool operator()(const pair<pii,LL>& lhs, const pair<pii,LL>& rhs)
    {
        return (lhs.fi.fi-lhs.fi.fi/2)*lhs.fi.se < (rhs.fi.fi-rhs.fi.fi/2)*rhs.fi.se;
    }
};
vector<LL> cost1, cost2;

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    LL tc;
    cin >> tc;
    while (tc--) {
        LL n,s;
        cin >> n >> s;
        LL ans = INT_MAX;
        map<pii,LL> m;
        map<pii,LL> cost;
        for (LL i=1;i<n;i++) {
            LL x,y,w,c;
            cin >> x >> y >> w >> c;
            m[{x,y}] = w;
            m[{y,x}] = w;
            cost[{y,x}] = c;
            cost[{x,y}] = c;
            adj[x].pb(y);
            adj[y].pb(x);
        }
        dfs(1);
        // for (LL i=1;i<=n;i++) {
        //     cout << sz[i] << " ";
        // }
        LL sum = 0;
        for (LL i=2;i<=n;i++) {
            // cout << par[i] << " " << i << " ";
            LL w = m[{par[i], i}], c = cost[{par[i], i}];
            sum += w * sz[i];
            if (c == 1) {
                while (w) {
                    cost1.pb((w-w/2)*sz[i]);
                    w /= 2;
                }
            } else {
                while (w) {
                    cost2.pb((w-w/2)*sz[i]);
                    w /= 2;
                }
            }
            // cout << w << " " << sz[i] << endl;
        }
        // for (auto x : cost1) cout << x << " ";
        // cout << endl;
        // for (auto x : cost2) cout << x << " ";
        // cout << endl;
        sort (cost1.begin(), cost1.end());
        sort (cost2.begin(), cost2.end());
        reverse(cost1.begin(), cost1.end());
        reverse(cost2.begin(), cost2.end());
        for (LL i=1;i<cost1.size();i++) cost1[i] += cost1[i-1];
        for (LL i=1;i<cost2.size();i++) cost2[i] += cost2[i-1];
        LL cost1sz = cost1.size();
        // for (auto x : cost1) cout << x << " ";
        // cout << endl;
        // for (auto x : cost2) cout << x << " ";
        // cout << endl;
        for (LL i=-1;i<cost1sz;i++) {
            LL need;
            if (i == -1) {
                need = sum-s;
            } else {
                need = sum-s-cost1[i];
            }
            LL l = 0, h = cost2.size()-1, dua = -1;
            if (need <= 0) {
                ans = min(ans, i+1);
                continue;
            }
            if (cost2.empty()) continue;
            while (l <= h) {
                LL mid = (l+h)/2;
                if (cost2[mid] >= need) {
                    dua = mid;
                    h = mid-1;
                } else {
                    l = mid+1;
                }
            }
            // cout << need << " " << i << " " << dua << endl;
            if (dua != -1) {
                ans = min(ans, i+1+2*(dua+1));
            }
        }
        cout << ans << endl;

        cost1.clear();
        cost2.clear();
        for (LL i=1;i<=n;i++) {
            adj[i].clear();
        }
        memset (par,0,sizeof(par));
        memset (vis,0,sizeof(vis));
        memset (sz,0,sizeof(sz));
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
/*
1
8 100
1 3 50
1 5 10
3 2 30
3 6 20
5 7 5
5 4 27
5 8 15
*/