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
    int tc;
    cin >> tc;
    while (tc--) {
        int n,k,l;
        cin >> n >> k >> l;
        int a[n+5];
        for (int i=1;i<=n;i++) cin >> a[i];
        a[0] = -999;
        int p[2*k+5];
        for (int i=0;i<=k;i++) {
            p[i] = i;
        }
        int x = 1;
        for (int i=2*k-1;i>=k+1;i--) {
            p[i] = x;
            x++;
        }

        bool vis[n+5][2*k+5];
        memset (vis,0,sizeof(vis));

        stack<pii> s;
        s.push({0,0});
        vis[0][0] = 1;
        while (!s.empty()) {
            pii cur = s.top();
            s.pop();
            if (!vis[cur.fi][(cur.se+1)%(2*k)]) {
                if (a[cur.fi]+p[(cur.se+1)%(2*k)] <= l) {
                    vis[cur.fi][(cur.se+1)%(2*k)] = 1;
                    s.push({cur.fi, (cur.se+1)%(2*k)});
                }
            }
            if (cur.fi < n && !vis[cur.fi+1][(cur.se+1)%(2*k)]) {
                if (a[cur.fi+1]+p[(cur.se+1)%(2*k)] <= l) {
                    vis[cur.fi+1][(cur.se+1)%(2*k)] = 1;
                    s.push({cur.fi+1, (cur.se+1)%(2*k)});
                }
            }
        }
        bool y = 0;
        for (int i=0;i<2*k;i++) if (vis[n][i]) y = 1;
        if (y) cout << "YES"; else cout << "NO";
        cout << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}