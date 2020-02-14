#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<LL,LL>
#define LL long long
using namespace std;

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    LL n,a,b,k;
    cin >> n >> a >> b >> k;
    LL p[n+5];
    for (LL i=1;i<=n;i++) cin >> p[i];
    for (LL i=1;i<=n;i++) {
        p[i]%=(a+b);
        // cout << p[i] << " ";
        if (p[i] == 0) p[i] = ((b)+a-1)/a;
        else if (p[i] <= a) p[i] = 0;
        else {
            p[i] -= a;
            p[i] = (p[i]+a-1)/a;
        }
    }
    // cout << endl;
    vector<LL> v;
    LL ans = 0;
    for (LL i=1;i<=n;i++) {
        if (p[i] == 0) ans++;
        else {
            v.pb(p[i]);
        }
    }
    sort (v.begin(), v.end());
    for (LL i=0;i<v.size();i++) {
        if (v[i] <= k) {
            k -= v[i];
            ans++;
        }
    }
    cout << ans << endl;
    
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}