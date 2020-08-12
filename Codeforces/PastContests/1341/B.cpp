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
        int n,k;
        cin >> n >> k;
        int a[n+5];
        for (int i=1;i<=n;i++) cin >> a[i];
        int b[n+5];
        memset (b,0,sizeof(b));
        for (int i=2;i<n;i++) {
            if (a[i] > a[i+1] && a[i] > a[i-1]) b[i] = 1;
        }
        for (int i=2;i<=n;i++) {
            b[i] += b[i-1];
        }
        int ans = -1, ansl = 0;
        for (int i=1;i<=n-k+1;i++) {
            int x = b[i+k-1]-b[i-1];
            if (b[i] > b[i-1]) x--;
            if (b[i+k-1] > b[i+k-2]) x--;
            // cout << i+k-1 << " " << i << " " << x << endl;
            if (x > ans) {
                ans = x;
                ansl = i;
            }
        }
        cout << ans+1 << " " << ansl << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}