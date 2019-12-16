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
        int n;
        cin >> n;
        // bool a[n+5];
        // memset (a,0,sizeof(a));
        // for (int i=1;i<=n;i++) {
        //     a[n/i]=1;
        // }
        // for (int i=1;i<=n;i++) if (a[i]) cout << i << " ";
        // cout << endl;
        vector<int> ans;
        set<int> p;
        ans.pb(0);
        for (int i=1;i*i<=n;i++) {
            if (p.find(i) == p.end()) {
                p.insert(i);
                ans.pb(i);
            }
            if (p.find(n/i) == p.end()) {
                p.insert(n/i);
                ans.pb(n/i);
            }
        }
        sort (ans.begin(), ans.end());
        cout << ans.size() << endl;
        for (int i=0;i<ans.size();i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}