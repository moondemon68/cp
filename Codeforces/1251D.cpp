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
    while(tc--) {
        LL n,s;
        cin >> n >> s;
        pii a[n+5];
        for (LL i=1;i<=n;i++) cin >> a[i].fi >> a[i].se;
        sort (a+1,a+n+1);
        reverse(a+1,a+n+1);
        LL l=a[n/2+1].fi,r=1000000007,ans=a[n/2+1].fi;
        while (l<=r) {
            LL cnt=0;
            LL mid = (l+r)/2;
            LL x = s;
            pii b[n+5];
            for (int i=1;i<=n;i++) b[i]=a[i];
            vector<pii> p;
            for (LL i=1;i<=n;i++) {
                x-=b[i].fi;
                if (b[i].fi>=mid) cnt++; else p.pb(mp(mid-b[i].fi, b[i].se-b[i].fi));
            }
            for (int i=0;i<p.size();i++) {
                if (p[i].fi<=p[i].se && x>=p[i].fi) {
                    x-=p[i].fi;
                    cnt++;
                }
            }
            if (cnt >= n/2+1) {
                ans = mid;
                l = mid+1;
            } else {
                r = mid-1;
            }
            // cout << mid <<  " " << cnt << " " << x << endl;
        }
        cout << ans << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}