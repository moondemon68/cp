#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define INF 1234567890
#define pii pair<LL,LL>
#define LL long long
using namespace std;

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    LL n,m;
    cin >> n >> m;
    LL a[n+5];
    for (LL i=1;i<=n;i++) {
        cin >> a[i];
    }
    map<LL,LL> mod;
    for (LL i=1;i<=n;i++) {
        mod[a[i] % m]++;
    }
    vector<LL> v;
    for (auto x : mod) {
        v.pb(x.fi);
    }
    LL p = v.size();
    for (auto x : mod) {
        v.pb(x.fi + m);
    }
    // for (LL i=0;i<v.size();i++) {
    //     cout << v[i] << " ";
    // }
    // cout << endl;
    LL ans = INT_MAX;
    for (LL i=0;i<p;i++) {
        LL x = v[i+p-1] - v[i];
        // cerr << x << " ";
        ans = min(ans, x);
    }
    // cerr << endl;
    cout << ans << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}