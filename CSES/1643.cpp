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
    LL n;
    cin >> n;
    LL a[n+5];
    for (LL i=1;i<=n;i++) cin >> a[i];
    LL cur=0,ans=-123456789;
    for (LL i=1;i<=n;i++) {
        cur+=a[i];
        if (cur<0) cur=0;
        ans=max(ans,cur);
    }
    sort (a+1,a+n+1);
    if (a[n]<0) cout << a[n] << endl;
    else cout << ans << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}