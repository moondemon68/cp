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
    LL a[100];
    LL p[100];
    memset (a,0,sizeof(a));
    a[1] = 1;
    p[0] = 1;
    for (LL i=2;i<=60;i++) {
        a[i] = 2 * a[i-1] + i;
    }
    for (LL i=1;i<=60;i++) {
        p[i] = 2 * p[i-1];
    }
    for (LL i=1;i<=60;i++) {
        p[i]--;
    }
    LL tc;
    cin >> tc;
    while (tc--) {
        LL x;
        cin >> x;
        LL ans = 0;
        vector<LL> v;
        while (x > 0) {
            v.pb(x%2);
            x /= 2;
        }
        for (LL i=0;i<v.size();i++) {
            // cout << v[i];
            if (v[i]) ans += p[i+1];
        }
        // cout << ": ";
        cout << ans << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}