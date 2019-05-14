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
    LL n,m;
    cin >> n >> m;
    LL a[n+5],b[m+5];
    for (LL i=1;i<=n;i++) cin >> a[i];
    for (LL i=1;i<=m;i++) cin >> b[i];
    LL ans=0;
    for (LL i=1;i<=n;i++) ans+=a[i];
    ans*=m;
    LL maxi=0;
    for (LL i=1;i<=n;i++) maxi=max(maxi,a[i]);
    for (LL i=1;i<=m;i++) {
        if (maxi>b[i]) {
            cout << -1 << endl;
            return 0;
        }
    }
    LL max1=0,max2=0,max1l=0;
    for (LL i=1;i<=n;i++) {
        if (a[i]>max1) {
            max1=a[i];
            max1l=i;
        }
    }
    a[max1l]=-1;
    for (LL i=1;i<=n;i++) max2=max(max2,a[i]);
    sort (b+1,b+m+1);
    if (b[1]==max1) {
        for (LL i=1;i<=m;i++) ans+=b[i]-max1;
    } else {
        ans+=b[1]-max2;
        for (LL i=2;i<=m;i++) ans+=b[i]-max1;
    }
    cout << ans << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}