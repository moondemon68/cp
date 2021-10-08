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

const LL MAXN = 300000;
LL k[MAXN + 5];
LL c[MAXN + 5];
bool taken[MAXN + 5];

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    LL tc;
    cin >> tc;
    while (tc--) {
        LL n,m;
        cin >> n >> m;
        for (LL i=1;i<=n;i++) cin >> k[i];
        for (LL i=1;i<=m;i++) {
            cin >> c[i];
            taken[i] = 0;
        }
        sort (k+1,k+n+1);
        LL cur = 1;
        LL ans = 0;
        for (LL i=n;i>=1;i--) {
            while (cur < m && taken[cur]) {
                cur++;
            }
            if (cur < k[i]) {
                ans += c[cur];
                taken[cur] = 1;
            } else if (cur == k[i]) {
                ans += c[cur];
            } else {
                ans += c[k[i]];
            }
        }
        cout << ans << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}