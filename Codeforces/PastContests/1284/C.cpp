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
    LL n,m;
    cin >> n >> m;
    LL f[n+5];
    f[1] = 1;
    for (int i=2;i<=n;i++) f[i] = (f[i-1] * i) % m;
    LL ans = 0;
    // for (int i=1;i<=n;i++) {
    //     for (int j=i;j<=n;j++) {
    //         ans += f[j-i+1] * f[n-j+i];
    //         ans %= m;
    //     }
    // }
    for (int i=1;i<=n;i++) {
        ans += ((f[i] * f[n-i+1]) % m) * ((n-i+1) % m);
        ans %= m;
    }
    cout << ans << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}