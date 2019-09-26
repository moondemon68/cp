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
    pii a[n+5];
    for (LL i=1;i<=n;i++) cin >> a[i].fi;
    for (LL i=1;i<=n;i++) cin >> a[i].se;
    sort (a+1,a+n+1);
    LL ans=0;
    bool d[n+5];
    memset (d,0,sizeof(d));
    for (int i=1;i<=n;i++) {
        if (d[i]) continue;
        bool y=0;
        for (int j=1;j<=n;j++) {
            if (i!=j&&a[i].fi==a[j].fi) y=1;
        }
        if (!y) continue;
        for (int j=1;j<=n;j++) {
            if ((a[i].fi|a[j].fi)==a[i].fi&&!d[j]) {
                ans+=a[j].se;
                d[j]=1;
            }
        }
    }
    cout << ans << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}