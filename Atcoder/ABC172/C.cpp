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

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    LL n,m,k;
    cin >> n >> m >> k;
    LL a[n+5], b[m+5];
    memset (a,0,sizeof(a));
    memset (b,0,sizeof(b));
    for (LL i=1;i<=n;i++) {
        cin >> a[i];
        a[i] += a[i-1];
    }
    for (LL i=1;i<=m;i++) {
        cin >> b[i];
        b[i] += b[i-1];
    }
    
    LL ansreal = 0;
    for (LL i=0;i<=n;i++) {
        LL x = i;
        LL rem = k - a[x];
        if (rem < 0) continue;
        LL l = 1, r = m, ans = 0;
        while (l <= r) {
            LL mid = (l+r) / 2;
            if (b[mid] <= rem) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        ansreal = max(ansreal, i+ans);
    }
    cout << ansreal << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}