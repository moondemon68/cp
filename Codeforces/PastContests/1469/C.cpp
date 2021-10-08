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
        int l = a[1], h = a[1];
        bool y = 1;
        for (int i=2;i<=n;i++) {
            int newl = l - k + 1, newh = h + k - 1;
            if (newl > a[i] + k - 1) y = 0;
            if (newl < a[i]) newl = a[i];
            if (newh > a[i] + k - 1) newh = a[i] + k - 1;
            if (newh < a[i]) y = 0;
            if (newl > newh) y = 0;
            l = newl;
            h = newh;
            // cout << l << " " << h << endl;
        }
        if (y && l <= a[n] && a[n] <= h) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}