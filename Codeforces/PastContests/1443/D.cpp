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
        int n;
        cin >> n;
        int a[n+5];
        for (int i=1;i<=n;i++) cin >> a[i];
        int b[n+5];
        b[1] = a[1];
        int c[n+5];
        c[1] = 0;
        bool y = 1;
        for (int i=2;i<=n;i++) {
            b[i] = min(b[i-1], a[i]-c[i-1]);
            if (b[i] < 0) y = 0;
            c[i] = a[i] - b[i];
            if (c[i] < 0) y = 0;
        }
        // for (int i=1;i<=n;i++) cout << b[i] << " "; cout << endl;
        // for (int i=1;i<=n;i++) cout << c[i] << " "; cout << endl;
        if (y) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}