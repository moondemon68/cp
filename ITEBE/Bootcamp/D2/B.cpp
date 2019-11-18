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
        int n,c;
        cin >> n >> c;
        int a[n+5];
        for (int i=1;i<=n;i++) cin >> a[i];
        sort (a+1,a+n+1);
        int l = 0, h = 1e9, ans = 0;
        while (l <= h) {
            int m = (l+h) / 2, x = a[1], cnt = 1;
            for (int i=2;i<=n;i++) {
                if (a[i] - x >= m) {
                    cnt++;
                    x = a[i];
                }
            }
            if (cnt >= c) {
                ans = m;
                l = m + 1;
            } else {
                h = m - 1;
            }
        }
        cout << ans << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}