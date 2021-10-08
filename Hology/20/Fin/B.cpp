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

LL a[10000005];
int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    LL n, x, y;
    cin >> n >> x >> y;
    for (int i=1;i<=n;i++) a[i] = (LL)INT_MAX * (LL)INT_MAX;
    a[0] = 0;
    for (LL i=1;i<=n;i++) {
        if (i % 2 == 0) {
            a[i] = min(a[i], a[i/2] + y);
        }
        a[i] = min(a[i], a[i-1] + x);
    }
    cout << a[n] << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}