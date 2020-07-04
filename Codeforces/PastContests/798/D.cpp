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
    int n;
    cin >> n;
    pair<pii,int> a[n+5];
    for (int i=1;i<=n;i++) {
        cin >> a[i].fi.fi;
        a[i].se = i;
    }
    for (int i=1;i<=n;i++) cin >> a[i].fi.se;
    vector<int> ans;
    sort (a+1, a+n+1);
    reverse(a+1,a+n+1);
    // for (int i=1;i<=n;i++) cout << a[i].fi.fi << " " << a[i].fi.se << " " << a[i].se << endl;
    for (int i=n%2+1;i<n;i+=2) {
        if (a[i].fi.se <= a[i+1].fi.se) ans.pb(a[i+1].se);
        else ans.pb(a[i].se);
    }
    if (n%2 == 1) ans.pb(a[1].se);
    else {
        if (a[1].fi.se <= a[2].fi.se) ans.pb(a[1].se); else ans.pb(a[2].se);
    }
    cout << ans.size() << endl;
    for (auto x : ans) cout << x << " ";
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}