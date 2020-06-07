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
    int n,q;
    cin >> n >> q;
    int a[n+5];
    for (int i=1;i<=n;i++) cin >> a[i];
    int k[q+5];
    for (int i=1;i<=q;i++) cin >> k[i];
    int ans = -1, l = 0, h = 1e6;
    while (l <= h) {
        int m = (l+h) / 2;
        int cnt = 0;
        for (int i=1;i<=n;i++) {
            if (a[i] <= m) cnt++;
        }
        for (int i=1;i<=q;i++) {
            if (k[i] > 0 && k[i] <= m) cnt++;
            if (k[i] < 0 && k[i] * -1 <= cnt) cnt--;
        }
        if (cnt > 0) {
            ans = m;
            h = m-1;
        } else {
            l = m+1;
        }
    }
    if (ans == -1) cout << 0 << endl; else cout << ans << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}