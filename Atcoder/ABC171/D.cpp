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
    LL cnt[100005];
    memset (cnt,0,sizeof(cnt));
    LL ans = 0;
    for (LL i=1;i<=n;i++) {
        cnt[a[i]]++;
        ans += a[i];
    }
    LL q;
    cin >> q;
    while (q--) {
        LL x,y;
        cin >> x >> y;
        LL t = cnt[x];
        cnt[x] -= t;
        cnt[y] += t;
        ans -= x*t;
        ans += y*t;
        cout << ans << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}