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
        int a[n+5], b[n+5];
        for (int i=1;i<=n;i++) cin >> a[i];
        for (int i=1;i<=n;i++) cin >> b[i];
        vector<pii> v;
        for (int i=1;i<=n;i++) {
            if (b[i] == 0) {
                v.pb({a[i], i});
            }
        }
        sort (v.begin(), v.end());
        // reverse(v.begin(), v.end());
        int  p = 0, q = v.size()-1, cur = 0;
        int ans = 0;
        for (int i=1;i<=n;i++) {
            if (b[i] == 0) {
                // if (cur >= -1*v[p].fi && v[p].fi < 0) {
                //     cout << v[p].fi << " ";
                //     cur += v[p].fi;
                //     p++;
                // } else {
                    cout << v[q].fi << " ";
                    cur += v[q].fi;
                    q--;
                // }
            } else {
                cout << a[i] << " ";
                cur += a[i];
            }
            if (cur < 0) ans = i;
        }
        cout << endl;
        // cout << ans << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}