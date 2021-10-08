#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<LL,LL>
#define LL long long
using namespace std;

LL dsu[100005];
LL sum[100005];

LL find(LL x){
    if (x==dsu[x]) return x; else return find(dsu[x]);
}

void merge(LL u,LL v) {
    LL pu = find(u);
    LL pv = find(v);
    if (pu!=pv) {
        if (sum[pu]<sum[pv]) swap(pu,pv);
        sum[pu] += sum[pv];
        dsu[pv] = pu;
    }
}

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    LL n;
    cin >> n;
    LL a[n+5],p[n+5],g[n+5];
    memset (g,-1,sizeof(g));
    for (LL i=1;i<=n;i++) cin >> a[i];
    for (LL i=1;i<=n;i++) cin >> p[i];
    for (LL i=1;i<=n;i++) sum[i]=a[i];
    for (LL i=1;i<=n;i++) dsu[i]=i;
    LL ans[n+5];
    memset (ans,0,sizeof(ans));
    LL maxi=0;
    for (LL i=n;i>=1;i--) {
        ans[i]=maxi;
        LL x=p[i];
        g[x] = 0;
        if (g[x-1]==0) {
            merge(x,x-1);
        } 
        if (g[x+1]==0) {
            merge(x,x+1);
        }
        maxi=max(maxi,sum[find(x)]);
    }
    //for (LL i=1;i<=n;i++) cout << sum[i] << " ";
    //cout << endl;
    for (LL i=1;i<=n;i++) {
        cout << ans[i] << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}