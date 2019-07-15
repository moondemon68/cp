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
    LL n,m,c;
    cin >> n >> m >> c;
    LL a[m+5],b[m+5],price[m+5];
    for (LL i=1;i<=m;i++) cin >> a[i] >> b[i] >> price[i];
    LL ans=2000000000000;
    for (LL i=0;i<(1<<m);i++) {
        LL x=i;
        vector<LL> p;
        while (p.size()!=m) {
            p.pb(x%2);
            x/=2;
        }
        LL cost=0,cnt=0;
        bool d[n+5];
        memset (d,0,sizeof(d));
        for (LL j=0;j<p.size();j++) {
            if (p[j]==1) {
                cost+=price[j+1];
                for (LL k=a[j+1];k<=b[j+1];k++) d[k]=1;
            }
        }
        for (LL k=1;k<=n;k++) {
            if (!d[k]) cnt++;
        }
        cost+=cnt*c;
        ans=min(ans,cost);
    }
    cout << ans << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}