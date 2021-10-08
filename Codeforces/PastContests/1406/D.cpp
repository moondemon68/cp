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
    //clock_t start = clock();ye
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    LL n;
    cin >> n;
    LL a[n+5];
    for (LL i=1;i<=n;i++) cin >> a[i];
    LL b[n+5];
    memset (b,0,sizeof(b));
    for (LL i=1;i<n;i++) b[i] = a[i+1]-a[i];
    LL sum = 0;
    for (LL i=1;i<n;i++) {
        sum += max(b[i], 0LL);
    }
    cout << max(((a[1] + sum) / 2), (a[1] + sum) - ((a[1] + sum) / 2)) << endl;
    LL q;
    cin >> q;
    // cout << sum << endl;
    while (q--) {
        LL l,r,x;
        cin >> l >> r >> x;

        if (l == 1) a[1] += x;
        
        if (l > 1) {
            sum -= max(b[l-1], 0LL);
            b[l-1] += x;
            sum += max(b[l-1], 0LL);
        }

        if (r < n) {
            sum -= max(b[r], 0LL);
            b[r] -= x;
            sum += max(b[r], 0LL);
        }

        // for (LL i=1;i<n;i++) cout << b[i] << " ";
        // cout << sum << " ";
        // cout << endl;


        cout << max(((a[1] + sum) / 2), (a[1] + sum) - ((a[1] + sum) / 2)) << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}