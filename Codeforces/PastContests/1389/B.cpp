#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define INF 1234567890
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
        int n,k,z;
        cin >> n >> k >> z;
        int a[n+5];
        for (int i=1;i<=n;i++) cin >> a[i];
        int b[n+5];
        memset(b,0,sizeof(b));
        for (int i=1;i<=n;i++) {
            b[i] = b[i-1] + a[i];
        }

        int ans = a[1];
        for (int i=1;i<=k;i++) {
            for (int j=0;j<=z;j++) {
                int rem = k-2*j;
                if (rem >= i) {
                    int x = 0;
                    x += b[rem+1];
                    x += (a[i] + a[i+1])*j;
                    ans = max(ans, x);
                    // cout << 'x' << rem << " " << x << ", ";
                }
                if (rem == i-1) {
                    int x = 0;
                    x += b[rem];
                    x += (a[i] + a[i+1])*(j) + a[i];
                    ans = max(ans, x);
                    // cout << 'y' << rem << " " << x << ", ";
                }
            }
            // cout << endl;
        }
        cout << ans << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}