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
        int b[n+5];
        for (int i=1;i<=n;i++) cin >> a[i];
        for (int i=1;i<=n;i++) cin >> b[i];
        vector<pii> v,w;
        for (int i=1;i<=n;i++) {
            if (a[i] > a[n-i+1]) swap(a[i], a[n-i+1]);
            if (b[i] > b[n-i+1]) swap(b[i], b[n-i+1]);
            v.pb({a[i], a[n-i+1]});
            w.pb({b[i], b[n-i+1]});
        }
        sort (v.begin(), v.end());
        sort (w.begin(), w.end());
        bool y = 1;
        for (int i=0;i<v.size();i++) {
            if (v[i].fi != w[i].fi) y = 0;
            if (v[i].se != w[i].se) y = 0;
        }
        if (y) cout << "Yes"; else cout << "No";
        cout << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}