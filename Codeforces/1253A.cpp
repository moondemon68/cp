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
    while (tc--) {
        int n;
        cin >> n;
        int a[n+5], b[n+5];
        for (int i=1;i<=n;i++) {
            cin >> a[i];
        }
        for (int i=1;i<=n;i++) {
            cin >> b[i];
        }
        int x=0,xx=0, l=0,r=-1;
        for (int i=1;i<=n;i++) {
            if (a[i]!=b[i]) {
                x=a[i]-b[i];
                l=i;
                break;
            }
        }
        for (int i=n;i>=1;i--) {
            if (a[i]!=b[i]) {
                xx=a[i]-b[i];
                r=i;
                break;
            }
        }
        for (int i=l;i<=r;i++) {
            b[i]+=x;
        }
        bool y=1;
        for (int i=1;i<=n;i++) {
            if (a[i]!=b[i]) y=0;
        }
        if (x > 0) y=0;
        if (y) cout <<"YES" << endl;
        else cout << "NO" << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}