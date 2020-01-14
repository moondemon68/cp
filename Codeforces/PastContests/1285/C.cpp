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
    LL x;
    cin >> x;
    LL ans = 12345678987654321;
    for (LL i=1;i*i<=x;i++) {
        if (i/__gcd(i, x/i)*(x/i) == x) {
            if (max(i, x/i) < ans) {
                ans = max(i, x/i);
            }
        }
    }
    cout << x/ans << " " << ans << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}