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
    int a[n+5];
    a[0]=0;
    for (int i=1;i<=n;i++) cin >> a[i];
    a[n+1]=0;
    int l[n+5],r[n+5];
    memset (l,0,sizeof(l));
    memset (r,0,sizeof(r));
    for (int i=1;i<=n;i++) {
        if (a[i]>a[i-1]) l[i]=l[i-1]+1;
        else l[i]=1;
    }
    for (int i=n;i>=1;i--) {
        if (a[i]<a[i+1]) r[i]=r[i+1]+1;
        else r[i]=1;
    }
    int ans=1;
    for (int i=1;i<=n;i++) {
        if (i<n) ans=max(ans,l[i]+1);
        if (i>1) ans=max(ans,r[i]+1);
        if (a[i-1]+1<a[i+1]) ans=max(ans,l[i-1]+r[i+1]+1);
    }
    cout << ans << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}