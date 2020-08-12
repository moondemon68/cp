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
    LL a[n+5];
    for (int i=0;i<n;i++) cin >> a[i];
    vector<LL> v;
    for (int i=0;i<n;i+=2) {
        v.pb(a[i]);
    }
    for (int i=1;i<n;i+=2) {
        v.pb(a[i]);
    }
    for (int i=0;i<n;i+=2) {
        v.pb(a[i]);
    }
    for (int i=1;i<n;i+=2) {
        v.pb(a[i]);
    }
    for (int i=1;i<v.size();i++) {
        v[i] += v[i-1];
    }
    // for (auto x : v) cout << x << " ";
    // cout << endl;
    LL ans = 0;
    for (int i=1;i<=n;i++) {
        LL x = v[i+(n-1)/2] - v[i-1];
        // cout << x << endl;
        ans = max(ans, x);
    }
    cout << ans << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}