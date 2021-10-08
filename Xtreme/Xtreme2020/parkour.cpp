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
    LL n,q,sq,mk;
    cin >> n >> q >> sq >> mk;
    map<pii,int> m;
    pii a[n+5];
    for (LL i=1;i<=n;i++) {
        cin >> a[i].fi >> a[i].se;
        m[a[i]] = i;
    }
    LL as,bs,cs,at,bt,ct,ak,bk,ck;
    cin >> as >> bs >> cs >> at >> bt >> ct >> ak >> bk >> ck;
    LL s[q+5];
    LL t[q+5];
    LL k[q+5];
    for (LL i=1;i<=sq;i++) cin >> s[i] >> t[i] >> k[i];
    for (LL i=sq+1;i<=q;i++) s[i] = ((as * s[i-1] + bs * s[i-2] + cs) % n) + 1;
    for (LL i=sq+1;i<=q;i++) t[i] = ((at * t[i-1] + bt * t[i-2] + ct) % n) + 1;
    for (LL i=sq+1;i<=q;i++) k[i] = (ak * k[i-1] + bk * k[i-2] + ck) % mk;

    

    LL ans = 0, pow2 = 2;
    for (LL i=1;i<=q;i++) {
        bool vis[n+5];
        memset (vis,0,sizeof(vis));
        queue<LL> qu;
        qu.push(s[i]);
        vis[s[i]] = 1;
        while (!qu.empty()) {
            LL cur = qu.front();
            qu.pop();
            if (mk > 4) {
                for (LL j=1;j<=n;j++) {
                    if (abs(a[cur].fi - a[j].fi) + abs(a[cur].se - a[j].se) - 1 <= k[i] && !vis[j]) {
                        vis[j] = 1;
                        qu.push(j);
                        if (vis[t[i]]) break;
                    }
                }
            } else {
                for (LL j=-mk-1;j<=mk+1;j++) {
                    for (LL l=-mk-1;l<=mk+1;l++) {
                        if (abs(j) + abs(l) - 1 > (LL)mk) continue;
                        int next = m[{a[cur].fi+j, a[cur].se+l}];
                        if (next > 0 && !vis[next]) {
                            vis[next] = 1;
                            qu.push(next);
                            if (vis[t[i]]) break;
                        }
                    }
                }
            }
            if (vis[t[i]]) break;
        }

        if (vis[t[i]]) {
            ans += pow2;
        }
        ans %= MOD;
        pow2 *= 2;
        pow2 %= MOD;
    }
    cout << ans << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}