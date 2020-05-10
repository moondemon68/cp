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
        int n,m;
        cin >> n >> m;
        int a[n+5];
        for (int i=1;i<=n;i++) cin >> a[i];
        vector<int> v;
        for (int i=1;i<=m;i++) {
            int x;
            cin >> x;
            v.pb(x);
        }
        sort(v.begin(), v.end());
        v.pb(-1);
        int x = v[0];
        for (int i=0;i<m;i++) {
            if (v[i] == v[i+1]-1) {

            } else {
                // cout << "->" << x << " " << v[i] << endl;
                sort (a+x, a+v[i]+2);
                x = v[i+1];
            }
        }
        // for (int i=1;i<=n;i++) cout << a[i] << " ";
        // cout << endl;
        bool y = 1;
        for (int i=1;i<n;i++) {
            if (a[i]>a[i+1]) y = 0;
        }
        if (y) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}