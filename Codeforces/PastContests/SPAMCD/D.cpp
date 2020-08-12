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
    LL n;
    cin >> n;
    LL a[n+5];
    for (LL i=1;i<=n;i++) cin >> a[i];
    for (LL i=2;i<=n;i++) a[i] += a[i-1];
    a[0] = 0;
    LL ans = 0, r = 1;
    set<LL> s;
    s.insert(0);
    for (LL i=1;i<=n;i++) {
        while (r <= n && s.find(a[r]) == s.end()) {
            s.insert(a[r]);
            r++;
        }
        ans += r-i;
        // cout << r << " " << i << endl;
        s.erase(a[i-1]);
    }
    cout << ans << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}