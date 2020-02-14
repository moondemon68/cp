#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define LL long long
using namespace std;

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc;
    cin >> tc;
    while (tc--) {
        LL n, m;
        cin >> n >> m;
        if (m == 0) {
            cout << 0 << endl;
            continue;
        }
        LL ans = n*(n+1)/2;
        if (m >= n/2) ans -= (n-m);
        else {
            LL p = (n-m)/(m+1);
            LL q = (n-m)%(m+1);
            ans -= (m+1-q)*(p)*(p+1)/2;
            ans -= (q)*(p+2)*(p+1)/2;
        }
        cout << ans << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}