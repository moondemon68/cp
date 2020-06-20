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
        int p = 0;
        for (int i=1;i<=n;i++) {
            cin >> a[i];
            a[i] %= x;
            p += a[i];
        }
        if (p % x != 0) {
            cout << n << endl;
            continue;
        }
        int l = 0, r = 0;
        for (int i=1;i<=n;i++) {
            if (a[i] > 0) {
                l = i;
                break;
            }
        }
        for (int i=n;i>=1;i--) {
            if (a[i] > 0) {
                r = n-i+1;
                break;
            }
        }
        if (l == 0) {
            cout << -1 << endl;
        } else {
            cout << n-min(l,r) << endl;
        }
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}