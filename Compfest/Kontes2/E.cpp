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
    int tc;
    cin >> tc;
    while (tc--) {
        LL a = 0;
        LL n;
        cin >> n;
        n++;
        if (n % 2 == 1) {
            a = 3*n*n-3*n+1;
        } else {
            a = 3*n*n-6*n+6;
        }
        for (LL i=1;i<=n/2-1;i++) {
            for (LL j=1;j<=n/2-1;j++) {
                for (LL k=1;k<=n/2-1;k++) {
                    if ((n-i)*j*k == i*(n-j)*(n-k)) a -= 6;
                }
            }
        }
        cout << a << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}