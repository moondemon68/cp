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
    LL tc;
    cin >> tc;
    while (tc--) {
        LL a,b;
        cin >> a >> b;
        LL x = abs(a-b);
        LL ans=0;
        for (LL i=0;i<=100000;i++) {
            if (i*(i+1)/2 <= x) {
                ans = i;
            }
            else break;
        }
        LL t = ans*(ans+1)/2;
        if (x == t) cout << ans << endl;
        else if (ans%2 == 1) {
            if ((x-t) % 2 == 0) cout << ans+1 << endl; else cout << ans+2 << endl;
        }
        else {
            if ((x-t) % 2 == 1) cout << ans+1 << endl; else cout << ans+3 << endl;
        }
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}