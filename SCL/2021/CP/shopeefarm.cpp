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
        LL n, m;
        cin >> n >> m;
        LL pl = 0, pr = 0;
        for (LL j = 1; j <= n; j++) {
            LL a[m+5];
            for (LL i = 1; i <= m; i++) cin >> a[i];
            LL left = 0, right = 0, ml = 0, mr = 0;
            for (LL i = 1; i <= m; i++) {
                left += a[i];
                ml = max(ml, left);
            }
            for (LL i = m; i >= 1; i--) {
                right += a[i];
                mr = max(mr, right);
            }
            if (j == 1) {
                pl = ml;
                pr = max(0LL, left);
            } else {
                LL npl = max(pr, ml + pl);
				npl = max(npl, pr + right);
                LL npr = max(pl, mr + pr);
				npr = max(npr, pl + left);
                pl = npl;
                pr = npr;
            }
        }
        cout << max(pl, pr) << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}