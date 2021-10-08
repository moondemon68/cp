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
        LL a,b,k;
        cin >> a >> b >> k;
        pii p[k+5];
        for (LL i=1;i<=k;i++) cin >> p[i].fi;
        for (LL i=1;i<=k;i++) cin >> p[i].se;
        LL cnt[a+b+5];
        memset(cnt,0,sizeof(cnt));
        for (LL i=1;i<=k;i++) {
            cnt[p[i].fi]++;
            cnt[a+p[i].se]++;
        }
        LL ans = 0;
        for (LL i=1;i<=k;i++) {
            ans += k-cnt[p[i].fi]-cnt[a+p[i].se]+1;
        }
        cout << ans/2 << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}