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

LL divisors[10000005];
int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    LL n;
    cin >> n;
    
    memset (divisors, 0, sizeof(divisors));
    for (LL i = 1; i <= n; ++i)
        for (LL j = i; j <= n; j += i)
            ++divisors[j];

    LL ans = 0;
    for (LL i=1;i<=n;i++) {
        ans += i * divisors[i];
    }
    cout << ans << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}