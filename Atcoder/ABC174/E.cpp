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
    LL n,k;
    cin >> n >> k;
    LL a[n+5];
    for (LL i=1;i<=n;i++) cin >> a[i];
    LL l=1,r=1e9,ans=1e9;
    while (l <= r) {
        LL m = (l+r)/2;
        LL cnt = 0;
        for (LL i=1;i<=n;i++) {
            if (a[i] <= m) continue;
            cnt += (a[i])/m;
        }
        // cout << m << " " << cnt << endl;
        if (cnt <= k) {
            ans = m;
            r = m-1;
        } else if (cnt > k) {
            l = m+1;
        }
    }
    cout << ans << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}