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

const LL MAXN = 200005;
vector<LL> adj[MAXN];   // appliances that are affected
vector<LL> gen[MAXN];   // generatornya
LL a[MAXN];
LL sum[MAXN];
LL cur[MAXN];
LL lazy[MAXN];
int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    LL n,m;
    cin >> n >> m;
    for (LL i=1;i<=n;i++) cin >> a[i];
    memset (sum,0,sizeof(sum));
    memset (cur,0,sizeof(cur));
    for (LL i=1;i<=m;i++) {
        LL x;
        cin >> x;
        for (LL j=1;j<=x;j++) {
            LL p;
            cin >> p;
            sum[i] += a[p];
            adj[p].pb(i);
            gen[i].pb(p);
        }
    }
    for (LL i=1;i<=m;i++) {
        LL csum = sum[i];
        for (LL j=0;j<gen[i].size();j++) {
            csum -= a[gen[i][j]];
            cur[i] += csum * a[gen[i][j]];
        }
    }
    memset(lazy,0,sizeof(lazy));
    queue<LL> antri;
    LL q;
    cin >> q;
    while (q--) {
        LL type;
        cin >> type;
        if (type == 1) {
            int x,y;
            cin >> x >> y;
            if (lazy[x] == 0) antri.push(x);
            lazy[x] = y;
        } else {
            int x;
            cin >> x;
            while (!antri.empty()) {
                int p = antri.front();
                for (LL i=0;i<adj[p].size();i++) {
                    LL app = adj[p][i];
                    cur[app] += (sum[app] - a[p]) * (lazy[p] - a[p]);
                }
                lazy[p] = 0;
                antri.pop();
            }
            cout << cur[x] << endl;
        }
        // for (LL i=1;i<=m;i++) cout << cur[i] << " ";
    }

    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}