#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
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
    if (n==2) {
        cout << 1 << " " << abs(a[1]-a[2]) << endl;
        return 0;
    }
    LL maxi=0;
    for (LL i=1;i<=n;i++) maxi=max(maxi,a[i]);
    LL b[n+5];
    for (LL i=1;i<=n;i++) b[i] = maxi-a[i];
    LL g=b[1];
    for (LL i=1;i<=n;i++) {
        if (b[i]!=0) g = __gcd(g,b[i]);
    }
    LL ans=0;
    for (LL i=1;i<=n;i++) ans+=b[i]/g;
    cout << ans << " " << g << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}