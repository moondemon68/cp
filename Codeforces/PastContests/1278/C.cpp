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
        LL n;
        cin >> n;
        LL a[n+5], b[n+5];
        for (LL i=1;i<=n;i++) cin >> a[i];
        for (LL i=1;i<=n;i++) cin >> b[i];
        reverse(b+1,b+n+1);
        LL da[2*n+5], db[2*n+5];
        for (LL i=0;i<=2*n;i++) {
            da[i] = MOD; db[i] = MOD;
        }
        LL c1=0,c2=0;
        for (LL i=1;i<=n;i++) {
            if (a[i] == 1) c1++;
            else c2++;
            LL x = c1-c2;
            x += n;
            da[x] = min(da[x], n-i);
        }
        c1=0; c2=0;
        for (LL i=1;i<=n;i++) {
            if (b[i] == 1) c1++;
            else c2++;
            LL x = c1-c2;
            x += n;
            db[x] = min(db[x], n-i);
        }
        // for (LL i=0;i<=2*n;i++) cout << da[i] << " ";
        // cout << endl;
        // for (LL i=0;i<=2*n;i++) cout << db[i] << " ";
        // cout << endl;
        LL ans = 2*n;
        for (LL i=0;i<=2*n;i++) {
            LL x = 2*n-i;
            ans = min(ans, da[x]+db[i]);
        }
        if (da[n] != MOD) {
            ans = min(ans, n + da[n]);
        }
        if (db[n] != MOD) {
            ans = min(ans, n + db[n]);
        }
        cout << ans << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}