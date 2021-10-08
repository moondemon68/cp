#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define INF 1234567890
#define pii pair<LL,LL>
#define LL long long
using namespace std;

const LL MAXN = 200000;
LL a[MAXN+5];

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    LL n,m;
    cin >> n >> m;
    for (LL i=1;i<=n;i++) cin >> a[i];
    sort(a+1,a+n+1);
    LL ans = 0;
    for (LL i=2;i<=n;i++) {
        ans = __gcd(ans, a[i] - a[1]);
    }
    while (m--) {
        LL x;
        cin >> x;
        cout << __gcd(ans, a[1] + x) << " ";
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}