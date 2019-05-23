#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define LL long long
using namespace std;

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    LL n,k;
    cin >> n >> k;
    LL a[n+5];
    for (LL i=1;i<=n;i++) cin >> a[i];
    LL l=0,r=n,ans=0,anscost=0;
    while (l<=r) {
        LL m=(l+r)/2,cost=0;
        vector<LL> p;
        for (LL i=1;i<=n;i++) p.pb(a[i]+i*m);
        sort (p.begin(),p.end());
        for (LL i=0;i<m;i++) cost+=p[i];
        if (cost<=k) {
            ans=m;
            anscost=cost;
            l=m+1;
        } else r=m-1;
    }
    cout << ans << " " << anscost << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}