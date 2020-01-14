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
    LL tc;
    cin >> tc;
    while (tc--) {
        LL n;
        cin >> n;
        LL a[n+5];
        for (LL i=1;i<=n;i++) cin >> a[i];
        LL sum = 0;
        bool y = 1;
        for (LL i=1;i<n;i++) {
            sum += a[i];
            if (sum <= 0) y = 0;
        }
        sum = 0;
        for (LL i=n;i>1;i--) {
            sum += a[i];
            if (sum <= 0) y = 0;
        }
        if (y) cout << "YES"; else cout << "NO";
        cout << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}