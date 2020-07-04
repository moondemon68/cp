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
    LL n,k;
    cin >> n >> k;
    LL a[n+5];
    for (LL i=1;i<=n;i++) cin >> a[i];
    LL b[n+5];
    for (LL i=1;i<=n;i++) cin >> b[i];
    sort (a+1,a+n+1);
    reverse(a+1,a+n+1);
    sort (b+1,b+n+1);
    LL l = 0, h = 1e18, ans = 1e18;
    while (l <= h) {
        LL m = (l+h)/2;
        LL p = k;
        for (LL i=1;i<=n;i++) {
            if (a[i]*b[i] > m) {
                p -= (a[i]*b[i] - m + b[i] - 1) / b[i];
            }
        }
        if (p >= 0) {
            ans = m;
            h = m-1;
        } else {
            l = m+1;
        }
    }
    cout << ans << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}