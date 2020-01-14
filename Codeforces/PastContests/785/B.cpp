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
    int n,m;
    cin >> n;
    pii a[n+5];
    for (int i=1;i<=n;i++) cin >> a[i].fi >> a[i].se;
    cin >> m;
    pii b[m+5];
    for (int i=1;i<=m;i++) cin >> b[i].fi >> b[i].se;
    int p = b[1].fi;
    for (int i=1;i<=m;i++) {
        p = max(p, b[i].fi);
    }
    int ans = 0;
    for (int i=1;i<=n;i++) {
        if (a[i].se < p) {
            ans = max(ans, p - a[i].se);
        }
    }
    p = a[1].fi;
    for (int i=1;i<=n;i++) {
        p = max(p, a[i].fi);
    }
    for (int i=1;i<=m;i++) {
        if (b[i].se < p) {
            ans = max(ans, p - b[i].se);
        }
    }
    cout << ans << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}