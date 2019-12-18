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
    LL q;
    cin >> q;
    LL cnt=0;
    for (LL i=1;i<=n;i++) cnt += a[i];
    LL b[n+5];
    memset (b,0,sizeof(b));
    for (LL i=1;i<=n;i++) b[i]=a[i];
    map<LL,LL> m;
    while (q--) {
        LL x,y,z;
        cin >> x >> y >> z;
        LL c = x*MOD+y;
        if (m[c] != 0) {
            b[m[c]]++;
            if (b[m[c]] > 0 && b[m[c]] <= a[m[c]]) cnt++;
            m[c] = 0;
        }
        m[c] = z;
        b[m[c]]--;
        if (b[m[c]] >= 0) cnt--;
        cout << cnt << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}