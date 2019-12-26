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
        int n,p,k;
        cin >> n >> p >> k;
        int a[n+5];
        for (int i=1;i<=n;i++) cin >> a[i];
        sort (a+1,a+n+1);
        int ans = 0;
        int b[n+5];
        memset (b,0,sizeof(b));
        for (int i=1;i<=n;i++) {
            b[i] = a[i];
            b[i] += b[i-1];
        }
        for (int i=0;i<k;i++) {
            if (b[i] <= p) {
                int cur = i;
                int x = p - b[i];;
                for (int j = i+k;j<=n;j+=k) {
                    if (a[j] <= x) {
                        cur += k;
                        x -= a[j];
                    } else {
                        if (a[j-k+1] <= x) {
                            cur ++;
                            x -= a[j-k+1];
                        }
                        break;
                    }
                }
                ans = max (ans, cur);
            }
        }
        cout << ans << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}