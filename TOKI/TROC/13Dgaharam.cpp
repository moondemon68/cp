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

int dx[] = {0,-1,0,1};
int dy[] = {1,0,-1,0};
int par[90005];
int a[305][305];
bool pulau[305][305];
vector<pii> cell[90005];
int n,m;
int cnt = 0;

int get(int x, int y) {
    return (m*(x-1)+y);
}

int find(int u) {
    if (u == par[u]) return u;
    par[u] = find(par[u]);
    return par[u];
}

void merge(int u, int v) {
    if (find(u) == find(v)) return;
    par[find(v)] = find(u);
    cnt--;
}

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    set<int> s;
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=m;j++) {
            cin >> a[i][j];
            par[get(i,j)] = get(i,j);
            s.insert(a[i][j]);
        }
    }
    s.insert(0);
    vector<int> v;
    for (auto x:s) {
        v.pb(x);
    }
    map<int,int> p;
    int id = 0;
    for (auto x : v) {
        p[x] = id;
        id++;
    }
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=m;j++) {
            a[i][j] = p[a[i][j]];
            cell[a[i][j]].pb({i,j});
            // cout << a[i][j] << " ";
        }
        // cout << endl;
    }
    memset (pulau,0,sizeof(pulau));

    int ans = 0;
    for (int i=n*m+1;i>=1;i--) {
        for (int j=0;j<cell[i].size();j++) {
            int x = cell[i][j].fi, y = cell[i][j].se;
            cnt++;
            pulau[x][y] = 1;
            for (int k=0;k<4;k++) {
                int nextx = x+dx[k], nexty = y+dy[k];
                if (nextx >= 1 && nextx <= n && nexty >= 1 && nexty <= m && pulau[nextx][nexty]) {
                    merge(get(x,y), get(nextx, nexty));
                }
            }
        }
        // cout << cnt << " ";
        ans = max(ans, cnt);
    }
    cout << ans << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}