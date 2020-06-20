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

int a[305][305];
bool f[305][305];
bool vis[305][305];
int n,m;
int dx[] = {0,-1,0,1};
int dy[] = {1,0,-1,0};

int get(int x) {
    memset (f,0,sizeof(f));
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=m;j++) {
            if (a[i][j] >= x) f[i][j] = 1;
        }
    }
    int cnt = 0;
    memset (vis,0,sizeof(vis));
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=m;j++) {
            if (vis[i][j]) continue;
            if (!f[i][j]) continue;
            vis[i][j] = 1;
            cnt++;
            stack<pii> s;
            s.push({i,j});
            while (!s.empty()) {
                pii cur = s.top();
                s.pop();
                for (int k=0;k<4;k++) {
                    pii next = {cur.fi+dx[k], cur.se+dy[k]};
                    if (next.fi>=1 && next.fi <= n && next.se >= 1 && next.se <= m && !vis[next.fi][next.se] && f[next.fi][next.se]) {
                        vis[next.fi][next.se] = 1;
                        s.push(next);
                    }
                }
            }
        }
    }
    return cnt;
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
            s.insert(a[i][j]);
        }
    }
    s.insert(0);
    vector<int> v;
    int ans = 0;
    for (auto x:s) {
        v.pb(x);
        // ans = max(ans, get(x));
    }
    // cout << ans << endl;

    int l = 0, r = v.size()-1;
    while ((l + 10) <= r) {
        int m1 = (l*2+r) / 3;
        int m2 = (l+2*r) / 3;
        int x1 = get(v[m1]);
        int x2 = get(v[m2]);
        ans = max(x1, ans);
        ans = max(x2, ans);
        if (x1 > x2) {
            r = m2;
        } else if (x1 < x2) {
            l = m1;
        } else {
            l = m1;
            r = m2;
        }
        // cout << m1 << " " << get(v[m1]) << " " << m2 << " " << get(v[m2]) << endl;
    }
    for (int i=l;i<=r;i++) {
        ans = max(ans, get(v[i]));
    }
    // for (int i=0;i<=10;i++) {
    //     cout << i << " " << get(i) << endl;
    // }
    cout << ans << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}