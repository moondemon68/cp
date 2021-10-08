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
        int n;
        cin >> n;
        int a[n+5];
        for (int i=1;i<=n;i++) cin >> a[i];
        vector<int> adj[n+5];
        for (int i=1;i<=n;i++) {
            for (int j=1;j<=n;j++) {
                if (a[i] != a[j] && i != j) {
                    adj[i].pb(j);
                }
            }
        }
        bool done[n+5];
        memset (done,0,sizeof(done));
        map<int,int> col;
        vector<pii> ans;
        for (int i=1;i<=n;i++) {
            if (!done[i]) {
                done[i] = 1;
                if (col[a[i]]) {
                    for (auto next : adj[i]) {
                        ans.pb({i, next});
                        break;
                    }
                } else {
                    for (auto next : adj[i]) {
                        if (!done[next]) {
                            ans.pb({i, next});
                            done[next] = 1;
                        }
                        col[a[i]] = 1;
                    }
                }
            }
        }
        if (ans.size() == n-1) {
            cout << "YES" << endl;
            for (auto x : ans) cout << x.fi << " " << x.se << endl;
        } else cout << "NO" << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}