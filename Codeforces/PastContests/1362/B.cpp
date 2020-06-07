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
        vector<int> a;
        for (int i=1;i<=n;i++) {
            int x;
            cin >> x;
            a.pb(x);
        }
        int ans = -1;
        sort (a.begin(), a.end());
        for (int i=1;i<=1024;i++) {
            vector<int> v;
            for (int j=0;j<n;j++) {
                v.pb(i^a[j]);
            }
            sort (v.begin(), v.end());
            bool y = 1;
            for (int j=0;j<n;j++) {
                if (a[j] != v[j]) {
                    y = 0;
                    break;
                }
            }
            if (y) {
                ans = i;
                break;
            }
        }
        cout << ans << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}