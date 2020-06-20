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
    int n,k;
    cin >> n >> k;
    int a[n+5];
    for (int i=1;i<=n;i++) cin >> a[i];
    int l = 1, r = 1e9, ans = 1;
    while (l <= r) {
        int m = (l+r)/2;
        bool y = 0;
        int cnt = 0;
        for (int i=1;i<=n;i++) {
            if (!y) {
                if (a[i] <= m) {
                    cnt++;
                    y = 1;
                }
            } else {
                cnt++;
                y = 0;
            }
        }

        bool y2 = 1;
        int cnt2 = 0;
        for (int i=1;i<=n;i++) {
            if (!y2) {
                if (a[i] <= m) {
                    cnt2++;
                    y2 = 1;
                }
            } else {
                cnt2++;
                y2 = 0;
            }
        }

        if (cnt >= k || cnt2 >= k) {
            ans = m;
            r = m-1;
        } else {
            l = m+1;
        }
    }
    cout << ans << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}