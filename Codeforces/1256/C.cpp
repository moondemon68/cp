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
    int n,m,d;
    cin >> n >> m >> d;
    int a[m+5];
    for (int i=1;i<=m;i++) cin >> a[i];
    pii p[m+5];
    int x=1;
    for (int i=1;i<=m;i++) {
        p[i]=mp(x, x+a[i]-1);
        x+=a[i];
    }
    p[m+1]=mp(n+1,n+1);
    for (int i=m;i>=1;i--) {
        if (p[i+1].fi - p[i].se > d) {
            int diff = p[i+1].fi - p[i].se - d;
            p[i].se+=diff;
            p[i].fi+=diff;
        }
    }
    int ans[n+5];
    memset (ans,0,sizeof(ans));
    for (int i=1;i<=m;i++) {
        for (int j=p[i].fi;j<=p[i].se;j++) ans[j]=i;
    }
    if (p[1].fi <= d) {
        cout << "YES" << endl;
        for (int i=1;i<=n;i++) cout << ans[i] << " ";
    } else {
        cout << "NO" << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}