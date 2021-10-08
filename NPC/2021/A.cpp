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

const LL MAXN = 2000;
LL a[MAXN+5][MAXN+5];
int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    for (LL i=1;i<=MAXN;i++) {    // n
        a[i][i] = 1;
        a[i][1] = 1;
        for (LL j=2;j<MAXN;j++) { // k
            if (j > i) a[i][j] = 0;
            else a[i][j] = a[i-1][j-1] + a[i-j][j];
            a[i][j] %= MOD;
        }
    }
    // for (LL i=1;i<=15;i++) {
    //     for (LL j=1;j<=15;j++) {
    //         cout << a[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    LL tc;
    cin >> tc;
    while (tc--) {
        LL n, k;
        cin >> n >> k;
        cout << a[n+k][k] << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}