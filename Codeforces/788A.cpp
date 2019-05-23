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
    LL a[n+5];
    for (int i=1;i<=n;i++) cin >> a[i];
    LL dp1[n+5],dp2[n+5];
    memset (dp1,0,sizeof(dp1));
    memset (dp2,0,sizeof(dp2));
    for (int i=1;i<n;i++) {
        if (i%2==0) {
            dp1[i]=abs(a[i]-a[i+1])*-1;
            dp2[i]=abs(a[i]-a[i+1]);
        } else {
            dp1[i]=abs(a[i]-a[i+1]);
            dp2[i]=abs(a[i]-a[i+1])*-1;
        } 
    }
    /*
    for (int i=1;i<=n;i++) cout << dp1[i] << " ";
    cout << endl;
    for (int i=1;i<=n;i++) cout << dp2[i] << " ";
    cout << endl;
    */
    LL ans1=0,ans2=0;
    for (int i=1;i<=n;i++)  {
        ans1+=dp1[i];
        if (ans1<0) ans1=0;
        ans2+=dp2[i];
        if (ans2<0) ans2=0;
    }
    //cout << ans1 << " " << ans2 << endl;
    cout << ans1+ans2 << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}