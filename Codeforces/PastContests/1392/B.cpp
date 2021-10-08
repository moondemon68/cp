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
        LL n,k;
        cin >> n >> k;
        LL a[n+5];
        for (int i=1;i<=n;i++) cin >> a[i];
        if (n == 1) {
            cout << 0 << endl;
            continue;
        }
        LL maxi = INT_MIN;
        for (int i=1;i<=n;i++) {
            maxi = max(maxi, a[i]);
        }
        LL b[n+5];
        for (int i=1;i<=n;i++) {
            b[i] = maxi-a[i];
        }
        maxi = INT_MIN;
        for (int i=1;i<=n;i++) {
            maxi = max(maxi, b[i]);
        }
        LL c[n+5];
        for (int i=1;i<=n;i++) {
            c[i] = maxi-b[i];
        }
        if (k % 2 == 1) {
            for (int i=1;i<=n;i++) cout << b[i] << " ";
        } else {
            for (int i=1;i<=n;i++) cout << c[i] << " ";
        }
        cout << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}