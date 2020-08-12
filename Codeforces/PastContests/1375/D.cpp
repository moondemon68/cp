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
        for (int i=0;i<n;i++) cin >> a[i];
        vector<int> ans;
        set<int> s;
        for (int j=0;j<n;j++) {
            s.insert(a[j]);
        }
        int mex = 0;
        while (s.find(mex) != s.end()) mex++;
        while (mex != n) {
            ans.pb(mex+1);
            a[mex] = mex;
            set<int> ss;
            for (int j=0;j<n;j++) {
                ss.insert(a[j]);
            }
            int mexx = 0;
            while (ss.find(mexx) != ss.end()) mexx++;
            mex = mexx;
        }
        // for (int i=0;i<n;i++) cout << a[i] << " ";
        // cout << endl;
        // return 0;
        bool vis[n+5];
        memset (vis,0,sizeof(vis));
        for (int i=0;i<n;i++) {
            if (vis[i]) continue;
            if (a[i] != i) {
                ans.pb(i+1);
                int x = a[i];
                while (x != i) {
                    // cout << i+1 << endl;
                    ans.pb(x+1);
                    vis[x] = 1;
                    x = a[x];
                }
                ans.pb(x+1);
                vis[x] = 1;
            }
        }
        cout << ans.size() << endl;
        for (int i=0;i<ans.size();i++) cout << ans[i] << " ";
        cout << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}