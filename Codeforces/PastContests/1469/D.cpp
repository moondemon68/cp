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

int a[200005];
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
        for (int i=1;i<=n;i++) a[i] = i;
        vector<pii> ans;
        int cur = n;
        vector<int> v;
        while (cur > 1) {
            cur = ceil(sqrt(cur));
            v.pb(cur);
        }
        sort (v.begin(), v.end());

        for (int i=2;i<n;i++) {
            bool y = 1;
            for (auto x : v) {
                if (x == i) y = 0;
            }
            if (y) {
                a[i] = (a[i] + a[i+1] - 1) / a[i+1];
                ans.pb({i, i+1});
            }
        }
        v.pb(n);
        for (int i=v.size()-1;i>=1;i--) {
            a[v[i]] = (a[v[i]] + a[v[i-1]] - 1) / a[v[i-1]];
            ans.pb({v[i], v[i-1]});
        }
        for (int i=0;i<v.size()-1;i++) {
            while (a[v[i]] != 1) {
                a[v[i]] = (a[v[i]] + a[v[i+1]] - 1) / a[v[i+1]];
                ans.pb({v[i], v[i+1]});
            }
        }
        for (int i=n-1;i<=n;i++) cout << a[i] << " ";
        cout << endl;
        cout << "SIZE: " << ans.size() << endl;
        // cout << ans.size() << endl;
        // for (auto x : ans) {
        //     cout << x.fi << " " << x.se << endl;
        // }
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}