#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
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
        int n,k;
        cin >> n >> k;
        set<int> s;
        for (int i=1;i<=n;i++) {
            int x;
            cin >> x;
            s.insert(x);
        }
        if (s.size() > k) {
            cout << -1 << endl;
        } else {
            vector<int> ans;
            for (int i=1;i<=n;i++) {
                for (int j=0;j<k-s.size();j++) ans.pb(1);
                for (auto x : s) ans.pb(x);
            }
            cout << ans.size() << endl;
            for (auto x : ans) cout << x << " ";
            cout << endl;
        }
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}