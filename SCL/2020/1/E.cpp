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
    LL n,k;
    cin >> n >> k;
    LL ans = 0;
    LL a[n+5][3];
    for (LL i=1;i<=n;i++) {
        cin >> a[i][0] >> a[i][1] >> a[i][2];
    }
    while (k--) {
        LL mx = -10000000, x1 = -1, y1 = -1, x2 = -1, y2 = -1;
        for (LL i=1;i<=n;i++) {
            if (a[i][0] + a[i][1] > mx) {
                x1 = i;
                y1 = 0;
                x2 = i;
                y2 = 1;
                mx = a[i][0] + a[i][1];
            }
            if (a[i][2] + a[i][1] > mx) {
                x1 = i;
                y1 = 2;
                x2 = i;
                y2 = 1;
                mx = a[i][2] + a[i][1];
            }
        }
        for (LL i=0;i<=2;i++) {
            for (LL j=1;j<n;j++) {
                if (a[j][i] + a[j+1][i] > mx) {
                    x1 = j;
                    y1 = i;
                    x2 = j+1;
                    y2 = i;
                    mx = a[j][i] + a[j+1][i];
                }
            }
        }
        a[x1][y1] = -10000000;
        a[x2][y2] = -10000000;
        ans += mx;
    }
    cout << ans << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}