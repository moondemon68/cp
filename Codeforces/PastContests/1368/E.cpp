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
    srand ( unsigned ( time(0) ) );
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc;
    cin >> tc;
    while (tc--) {
        int n,m;
        cin >> n >> m;
        vector<int> adj[n+5];
        for (int i=1;i<=m;i++) {
            int x,y;
            cin >> x >> y;
            adj[x].pb(y);
        }
        vector<int> ans;
        for (int i=1;i<=n;i++) {
            if (adj[i].size() == 2) ans.pb(i);
        }
        random_shuffle ( ans.begin(), ans.end() );

        for (int i=1;i<=n;i++) {
            if (adj[i].size() != 2) {
                ans.pb(i);
            }
        }
        cout << min((int)ans.size(), 4*n/7) << endl;
        for (int i=0;i<min((int)ans.size(), 4*n/7);i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}