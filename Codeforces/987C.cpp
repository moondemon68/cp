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
    int n;
    cin >> n;
    pii a[n+5];
    for (int i=1;i<=n;i++) cin >> a[i].fi;
    for (int i=1;i<=n;i++) cin >> a[i].se;
    int ans=MOD;
    for (int i=2;i<n;i++) {
        int ansl=MOD,ansr=MOD;
        for (int j=1;j<i;j++) {
            if (a[j].fi<a[i].fi) ansl=min(ansl,a[j].se);
        }
        for (int j=i+1;j<=n;j++) {
            if (a[j].fi>a[i].fi) ansr=min(ansr,a[j].se);
        }
        if (ansl!=MOD&&ansr!=MOD) ans=min(ans,ansl+ansr+a[i].se);
    }
    if (ans==MOD) cout << -1 << endl; else cout << ans << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}