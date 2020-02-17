#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
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
        LL n, g, b;
        cin >> n >> g >> b;
        LL t = (n+1)/2;
        LL ans = 0;
        ans = (t/g) * (g+b);
        t %= g;
        if (t == 0) {
            ans -= (b);
        } else {
            ans += t;
        }
        if (ans < n) {
            cout << n << endl;
        } else {
            cout << ans << endl;
        }
            
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}