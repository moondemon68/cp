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
    LL n;
    cin >> n;
    LL a[n+5];
    for (LL i=1;i<=n;i++) cin >> a[i];
    LL x = 0;
    for (LL i=1;i<=n;i++) {
        x = max(x, a[i]);
    }
    for (LL i=1;i<=n;i++) {
        for (LL j=i+1;j<=n;j++) {
            x = max(x, a[i]|a[j]);
        }
    }
    for (LL i=1;i<=n;i++) {
        for (LL j=i+1;j<=n;j++) {
            for (LL k=j+1;k<=n;k++) {
                x = max(x, a[i]|a[j]|a[k]);
            }
        }
    }
    cout << x << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}