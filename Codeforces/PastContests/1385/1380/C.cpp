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
        int n,x;
        cin >> n >> x;
        int a[n+5];
        for (int i=1;i<=n;i++) cin >> a[i];
        sort (a+1, a+n+1);
        reverse(a+1,a+n+1);
        int ans = 0;
        int cur = MOD, cnt = 0;
        for (int i=1;i<=n;i++) {
            bool y = 0;
            if (cur == MOD) {
                cur = a[i];
                cnt++;
                y = 1;
            }
            if (cnt*cur >= x) {
                // cout << cur << " " << cnt << endl;
                cur = MOD;
                cnt = 0;
                ans++;
            } else {
                if (y) continue;
                cur = a[i];
                cnt++;
                if (cnt * cur >= x) {
                    // cout << cur << " " << cnt << endl;
                    cur = MOD;
                    cnt = 0;
                    ans++;
                }
            }
        }
        cout << ans << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}