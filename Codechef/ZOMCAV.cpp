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
        LL n;
        cin >> n;
        LL a[n+5];
        memset (a,0,sizeof(a));
        for (LL i=1;i<=n;i++) {
            LL x;
            cin >> x;
            if (i-x>=1) a[i-x-1]++;
            else a[0]++;
            if (i+x<=n) a[i+x]--;
        }
        LL b[n+5];
        for (LL i=1;i<=n;i++) cin >> b[i];
        for (LL i=1;i<=n;i++) a[i]+=a[i-1];
        //for (LL i=0;i<n;i++) cout << a[i] << " ";
        //cout << endl;
        vector<LL> c;
        for (LL i=0;i<n;i++) c.pb(a[i]);
        vector<LL> d;
        for (LL i=1;i<=n;i++) d.pb(b[i]);
        sort (c.begin(),c.end());
        sort (d.begin(),d.end());
        bool y=1;
        for (LL i=0;i<c.size();i++) if (c[i]!=d[i]) y=0;
        if (y) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}