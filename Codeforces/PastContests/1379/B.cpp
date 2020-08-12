#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define INF 1234567890
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
        LL l,r,m;
        cin >> l >> r >> m;
        LL bawah = l-r, atas = r-l;
        for (LL i=l;i<=r;i++) {
            LL p = 1, q = 1e10, ans = 12345678987654231;
            while (p <= q) {
                LL mid = (p+q)/2;
                LL x = mid*i;
                if (m-x < bawah) {
                    q = mid-1;
                } else if (m-x > atas) {
                    p = mid+1;
                } else {
                    ans = mid;
                    break;
                }
            }
            if (ans == 12345678987654231) continue;
            if (m-i*ans == 0) {
                cout << i << " " << l << " " << l << endl;
                break;
            } else if (m-i*ans > 0) {
                cout << i << " " << r << " " << r-(m-i*ans) << endl;
                break;
            } else {
                cout << i << " " << l << " " << l-(m-i*ans) << endl;
                break;
            }
            // cout << i << " " << ans << " " << m-i*ans << endl;
        }
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}