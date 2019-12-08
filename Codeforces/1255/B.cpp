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
    LL tc;
    cin >> tc;
    while (tc--) {
        LL n,m;
        cin >> n >> m;
        LL a[n+5];
        for (LL i=1;i<=n;i++) cin >> a[i];
        if (n>m || n == 2) {
            cout << -1 << endl;
            continue;
        }
        LL minx=INT_MAX, mini = 0, minj = 0;
        LL ans=0;
        for (LL i=1;i<=n;i++) {
            for (LL j=i+1;j<=n;j++) {
                if (a[i]+a[j] < minx) {
                    minx = a[i]+a[j];
                    mini = i;
                    minj = j;
                }
            }
        }
        vector<pii> p;
        for (LL i=1;i<=n;i++) {
            ans += a[i];
            LL x = i+1;
            if (x>n) x-=n;
            ans += a[x];
            p.pb(mp(i,x));
        }
        for (LL i=n+1;i<=m;i++) {
            ans+=minx;
            p.pb(mp(mini,minj));
        }
        cout << ans << endl;
        for (LL i=0;i<p.size();i++) cout << p[i].fi << " " << p[i].se << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}