#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define LL long long
using namespace std;

vector<pii> p[400005];
set<int> ada;

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,q;
    cin >> n >> q;
    int a[n+5];
    for (int i=1;i<=n;i++) cin >> a[i];
    a[n+1]=1000000007;
    a[n+2]=1000000008;
    int l=1,r=2,d=a[2]-a[1];
    while (l<=n && r <= n) {
        while (a[r]-a[r-1]==d && r <= n) {
            r++;
        }
        r--;
        ada.insert(d+200000);
        if (l==1||a[l]-a[l-1]!=d) p[d+200000].pb(mp(l,r));
        else p[d+200000].pb(mp(l-1,r));
        l=r;
        r++;
        d = a[r]-a[l];
    }
    // for (int i=0;i<=400000;i++) {
    //     if (p[i].size()!=0) {
    //         cout << i-200000 << endl;
    //         for (int j=0;j<p[i].size();j++) {
    //             cout << p[i][j].fi << " " << p[i][j].se << endl;
    //         }
    //     }
    // }
    while (q--) {
        int al,ar,ad;
        cin >> al >> ar >> ad;
        ad += 200000;
        int ans=1;
        for (int i=0;i<p[ad].size();i++) {
            ans=max(ans,min(p[ad][i].se,ar)-max(p[ad][i].fi,al)+1);
        }
        cout << ans << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}