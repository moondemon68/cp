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
    LL tc;
    cin >> tc;
    while (tc--) {
        LL n,s;
        cin >> n >> s;
        LL a[n+5];
        memset (a,0,sizeof(a));
        for (LL i=1;i<=n;i++) cin >> a[i];
        for (LL i=2;i<=n;i++) a[i]+=a[i-1];
        if (a[n] <= s) {
            cout << 0 << endl;
            continue;
        }
        LL ans=1, maxp=0;
        for (LL i=1;i<=n;i++) {
            if (a[i-1] > s) break;
            LL cur = i-1, left = s - a[i-1];
            // cout << cur << " " << left << " ";
            LL l = i, r = n, k = i;
            while (l <= r) {
                LL m = (l+r)/2;
                if (a[m] - a[i] > left) {
                    r = m - 1;
                } else {
                    k = m;
                    l = m + 1;
                }
            }
            LL recv = cur + (k - i);
            if (recv > maxp) {
                maxp = recv;
                ans = i;
            }
            // cout << recv << endl;
        }
        //cout << maxp << " ";
        cout << ans << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}