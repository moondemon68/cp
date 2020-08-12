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
        if (n%2 == 0) cout << n/2 << " " << n/2 << endl;
        else {
            vector<LL> v;
            for (LL i=2;i*i<=n;i++) {
                if (n%i == 0) {
                    v.pb(i); v.pb(n/i);
                }
            }
            if (v.empty()) {
                cout << 1 << " " << n-1 << endl;
            } else {
                sort (v.begin(), v.end());
                cout << v.back() << " " << n-v.back() << endl;
            }
        }
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}