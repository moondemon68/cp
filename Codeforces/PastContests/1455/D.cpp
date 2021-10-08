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
        int a[505];
        memset (a,0,sizeof(a));
        for (int i=1;i<=n;i++) cin >> a[i];
        bool y = 1;
        for (int i=1;i<n;i++) {
            if (a[i] > a[i+1]) y = 0;
        }
        if (y) {
            cout << 0 << endl;
            continue;
        }
        int cnt = 0;
        bool done = 0;
        for (int i=1;i<=n;i++) {
            if (a[i] > x) {
                swap(x, a[i]);
                cnt++;
            }
            y = 1;
            for (int j=1;j<n;j++) {
                if (a[j] > a[j+1]) {
                    y = 0;
                    break;
                }
            }
            if (y) {
                cout << cnt << endl;
                done = 1;
                break;
            }
        }
        y = 1;
        for (int i=1;i<n;i++) {
            if (a[i] > a[i+1]) y = 0;
        }
        if (!done) {
            if (y) cout << cnt << endl; else cout << -1 << endl;
        }
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}