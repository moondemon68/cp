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
    LL n,x;
    cin  >> n >> x;
    LL a[n+5];
    memset (a,0,sizeof(a));
    for (LL i=1;i<=n;i++) cin >> a[i];
    LL ans=INT_MAX, l=1,r=0,cur=0;
    while (l<n && r<n) {
        if (l>r) {
            r++;
            cur+=a[r];
        } else if (cur < x) {
            r++;
            cur+=a[r];
        } else {
            cur-=a[l];
            l++;
        }
        if (cur >= x) ans=min(ans,r-l+1);
    }
    if (ans!=INT_MAX) cout << ans << endl;
    else cout << -1 << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}