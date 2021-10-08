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
    LL a,b;
    cin >> a >> b;
    if (a < b) swap(a, b);
    LL dif = a-b;
    vector<LL> v;
    for (LL i=1;i*i<=dif;i++) {
        if ((dif%i) == 0) {
            v.pb(i);
            if (i * i != dif) v.pb(dif/i);
        }
    }
    sort(v.begin(), v.end());
    LL ans = 0, mini = INT_MAX;
    for (auto f : v) {
        LL d = dif/f;
        LL aminbperd = dif/d;
        LL bperd = (b+d-1)/d + 1;
        // aminbperd harus coprime sama bperd + x
        // aminb harus coprime sama b + x
        cout << aminbperd << " " << bperd << " ";
        LL x = 0;
        while (__gcd(aminbperd, bperd + x) != 1) {
            x++;
        }
        cout << d << " " << x << endl;
        x *= d;
        if ((a + x) * (b + x) / __gcd(a+x, b+x) < mini) {
            mini = (a + x) * (b + x) / __gcd(a+x, b+x) < mini;
            ans = x;
        }
    }
    cout << ans << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}