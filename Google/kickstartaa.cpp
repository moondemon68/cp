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
    int tc;
    cin >> tc;
    for (int t=1;t<=tc;t++) {
        int n;
        LL p;
        cin >> n >> p;
        LL a[n+5];
        for (int i=1;i<=n;i++) cin >> a[i];
        cout << "Case #" << t << ": ";
        sort (a+1,a+n+1);
        a[0]=0;
        LL b[n+5];
        for (int i=1;i<=n;i++) {
            b[i]=a[i];
            a[i]+=a[i-1];
            //cout << a[i] << " ";
        }
        //cout << endl;
        LL ans=12345678987654;
        for (int i=p;i<=n;i++) {
            //cout << b[i]*p-a[i]+a[i-p] <<" ";
            ans=min(ans,b[i]*p-a[i]+a[i-p]);
        }
        cout << ans << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}