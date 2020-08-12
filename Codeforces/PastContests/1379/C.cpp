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

bool cmp(pii a, pii b) {
    return a.fi > b.fi;
}

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
        pii a[m+5];
        for (LL i=1;i<=m;i++) cin >> a[i].fi >> a[i].se;
        sort (a+1,a+m+1,cmp);
        LL b[m+5];
        memset (b,0,sizeof(b));
        for (LL i=1;i<=m;i++) {
            b[i] = b[i-1] + a[i].fi;
        }
        LL answer = 0;
        for (LL i=1;i<=m;i++) {
            LL ans = 0;
            LL rem = n;
            LL x = a[i].se;
            LL l=1,h=m,ans1=0;
            while (l <= h) {
                LL mid = (l+h)/2;
                if (a[mid].fi >= x) {
                    ans1 = mid;
                    l = mid+1;
                } else {
                    h = mid-1;
                }
            }
            // ans1 = min(ans1, rem);
            // cout << ans1 << " " << b[ans1] << " ";
            if (ans1 < i) {
                ans += a[i].fi;
                rem--;
            }
            ans += b[min(ans1, rem)];
            // cout << ans << " ";
            rem -= min(rem, ans1);
            ans += x * rem;
            answer = max(answer, ans);
            // cout << ans1 << " " << ans << endl;
        }
        cout << answer << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}