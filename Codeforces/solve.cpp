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

const LL n = 500;
LL a[n+5][n+5], b[n+5][n+5];

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ifstream cin("input.txt");
    memset (a,0,sizeof(a));
    memset (b,0,sizeof(b));
    for (LL i=1;i<=n;i++) {
        for (LL j=1;j<=n;j++) {
            cin >> a[i][j];
            if (a[i][j] == -1) b[i][j] = 1; else b[i][j] = 0;
        }
    }
    for (LL i=1;i<=n;i++) {
        for (LL j=1;j<=n;j++) {
            a[i][j] += a[i][j-1];
            b[i][j] += b[i][j-1];
        }
    }
    for (LL i=1;i<=n;i++) {
        for (LL j=1;j<=n;j++) {
            a[i][j] += a[i-1][j];
            b[i][j] += b[i-1][j];
        }
    }
    LL ans = 0;
    for (LL i=1;i<=n;i++) {
        cout << i << endl;
        for (LL j=i;j<=n;j++) {
            for (LL k=1;k<=n;k++) {
                for (LL l=k;l<=n;l++) {
                    LL sum = a[j][l] - a[i-1][l] - a[j][k-1] + a[i-1][k-1];
                    LL bom = b[j][l] - b[i-1][l] - b[j][k-1] + b[i-1][k-1];
                    if (bom % 2 == 1) sum *= -1;
                    if (sum % 13 == 0) ans += sum;
                }
            }
        }
    }
    cout << ans << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}