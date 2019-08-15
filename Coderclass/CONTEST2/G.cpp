#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define INF 1234567890
#define pii pair<double,double>
#define LL long long
using namespace std;

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        double k;
        cin >> n >> k;
        double a[n+5];
        for (int i=1;i<=n;i++) cin >> a[i];
        sort (a+1,a+n+1);
        double t=0;
        if (n%2==0) {
            t=(a[n/2]+a[n/2+1])/2;
        } else {
            t=a[n/2+1];
        }
        double l=t-k/2,r=t+k/2;
        double ans=0;
        for (int i=1;i<=n;i++) {
            if (a[i]>=l&&a[i]<=r) {
                ans+=0;
            } else if (a[i]<l) {
                ans+=(l-a[i])*(l-a[i]);
            } else {
                ans+=(r-a[i])*(r-a[i]);
            }
        }
        cout << fixed << setprecision(10) << ans << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}