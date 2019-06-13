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
    while (cin >> n) {
        LL k;
        cin >> k;
        LL a[n+5];
        for (int i=1;i<=n;i++) cin >> a[i];
        a[0]=0;
        for (int i=1;i<=n;i++) a[i]+=a[i-1];
        bool y=0;
        for (int i=1;i<=n;i++) {
            int l=i,r=n,ans=-1;
            while (l<=r) {
                int m=(l+r)/2;
                if (a[m]-a[i-1]==k) {
                    ans=m;
                    break;
                } else if (a[m]-a[i-1]>k) {
                    r=m-1;
                } else {
                    l=m+1;
                }
            }
            if (ans!=-1) {
                y=1;
                cout << i << " " << ans << "\n";
                break;
            }
        }
        if (!y) cout << -1 << "\n";
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}