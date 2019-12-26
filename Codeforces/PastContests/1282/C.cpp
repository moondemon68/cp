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
        LL n,given,a,b;
        cin >> n >> given >> a >> b;
        bool d[n+5];
        for (LL i=1;i<=n;i++) cin >> d[i];
        LL t[n+5];
        for (LL i=1;i<=n;i++) cin >> t[i];
        pii c[n+5];
        for (LL i=1;i<=n;i++) c[i] = mp(t[i], d[i]);
        sort (c+1,c+n+1);
        LL req[n+5];
        memset (req, 0,sizeof(req));
        LL ca = 0, cb = 0;
        for (LL i=1;i<=n;i++) {
            req[i] += req[i-1];
            if (c[i].se == 0) req[i] += a;
            else req[i] += b;
            if (c[i].se == 0) ca++; else cb++;
        }
        LL ans=0;
        if (req[n] <= given) ans = n;
        c[0] = mp(0, 2);
        c[n+1].fi = given + 1;
        for (LL i=0;i<=n;i++) {
            //cout << req[i] << " " << c[i].fi << " ";
            if (c[i].se == 0) ca--; else if (c[i].se == 1) cb--;
            if (req[i] >= c[i+1].fi) {
                //cout << endl;
                continue;
            }
            //cout << ca << " " << cb << " ";
            LL cur = 0;
            if (req[i] <= c[i+1].fi - 1) cur = i;
            LL left = c[i+1].fi - 1;
            left = min(left, given);
            left = left - req[i];
            //cout << left << " ";
            LL takea = min(left/a, ca);
            left -= takea * a;
            cur += takea;
            LL takeb = min(left/b, cb);
            left -= takeb * b;
            cur += takeb;
            ans = max(ans, cur);
            //cout << cur << endl;
        }
        //cout << "ans: " << ans << endl;
        cout << ans << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}