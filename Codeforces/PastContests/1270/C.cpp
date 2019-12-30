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
        LL n;
        cin >> n;
        LL a[n+5];
        for (LL i=1;i<=n;i++) cin >> a[i];
        LL x = 0, sum = 0;
        for (LL i=1;i<=n;i++) {
            x ^= a[i];
            sum += a[i];
        }
        LL p = 0, q = 0;
        if (x*2 == sum) {
            cout << 0 << endl << endl;
        } else {
            p = x;
            q = sum+x;
            cout << 2 << endl << p << " " << q << endl;
            x ^= p;
            x ^= q;
            sum += p;
            sum += q;
        } 
        //cout << x*2 << " " << sum << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}