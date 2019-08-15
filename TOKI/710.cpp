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
        LL h[n+5],t[n+5];
        for (LL i=1;i<=n;i++) cin >> h[i];
        for (LL i=1;i<=n;i++) cin >> t[i];
        LL p[m+5];
        for (LL i=1;i<=m;i++) cin >> p[i];
        LL tot[m+5];
        memset (tot,0,sizeof(tot));
        for (LL i=1;i<=n;i++) {
            tot[t[i]]+=h[i];
        }
        for (LL i=1;i<=m;i++) {
            tot[i]=(tot[i]+p[i]-1)/p[i];
        }
        LL ans=-1,mini=0;
        for (LL i=1;i<=m;i++) {
            if (tot[i]>mini) {
                mini=tot[i];
                ans=i;
            }
        }
        cout << ans << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}