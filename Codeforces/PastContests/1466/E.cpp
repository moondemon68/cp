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

const int MAXN = 500000;
LL a[MAXN + 5];
LL ij[65][2];
LL kj[65][2];
LL p[65];

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    p[0] = 1;
    for (int i=1;i<=60;i++) p[i] = (p[i-1] * 2) % MOD;
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        for (int i=1;i<=n;i++) cin >> a[i];
        for (int i=0;i<60;i++) {
            ij[i][0] = 0;
            ij[i][1] = 0;
            for (int j=1;j<=n;j++) {
                ij[i][0] += ((a[j] >> i) & 1) & 0;
                ij[i][1] += ((a[j] >> i) & 1) & 1;
            }
        }
        for (int i=0;i<60;i++) {
            kj[i][0] = 0;
            kj[i][1] = 0;
            for (int j=1;j<=n;j++) {
                kj[i][0] += ((a[j] >> i) & 1) | 0;
                kj[i][1] += ((a[j] >> i) & 1) | 1;
            }
        }
        // cout << "IJ" << endl;
        // for (int i=0;i<5;i++) cout << ij[i][0] << " " << ij[i][1] << endl;
        // cout << "KJ" << endl;
        // for (int i=0;i<5;i++) cout << kj[i][0] << " " << kj[i][1] << endl;
        LL ans = 0;
        for (int j=1;j<=n;j++) {
            LL totij = 0, totkj = 0;
            for (int i=0;i<60;i++) {
                if ((a[j] >> i) & 1) {
                    totij += ((p[i] * ij[i][1]) % MOD);
                    totkj += ((p[i] * kj[i][1]) % MOD);
                    totij %= MOD;
                    totkj %= MOD;
                } else {
                    totij += ((p[i] * ij[i][0]) % MOD);
                    totkj += ((p[i] * kj[i][0]) % MOD);
                    totij %= MOD;
                    totkj %= MOD;
                }
            }
            ans += (totij * totkj) % MOD;
            ans %= MOD;
        }
        cout << ans << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}