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
        vector<int> ans;
        ans.pb(a[1]);
        int x = 0;
        if (a[1] > a[2]) x = -1;
        else if (a[1] < a[2]) x = 1;
        for (int i=2;i<n;i++) {
            if (a[i] > a[i+1] && x == 1) {
                x = -1;
                ans.pb(a[i]);
            } else if (a[i] < a[i+1] && x == -1) {
                x = 1;
                ans.pb(a[i]);
            }
        }
        ans.pb(a[n]);
        cout << ans.size() << endl;
        for (int i=0;i<ans.size();i++) cout << ans[i] << " ";
        cout << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}