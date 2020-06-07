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
        LL c,hot,t;
        cin >> hot >> c >> t;
        if (hot + c == t * 2) {
            cout << 2 << endl;
            continue;
        }
        // LL x = 0, y = 0;
        // for (int i=1;i<=10;i++) {
        //     if (y == 0) x += hot; else x += c;
        //     y = 1-y;
        //     cout << x/i << endl;
        // }
        LL l = 0, h = 1e9, ans = 0;
        while (l <= h) {
            LL m = (l + h) / 2;
            LL p = (m+1)*hot + m*c - t*(2*m+1);
            if (p >= 0) {
                ans = m;
                l = m+1;
            } else {
                h = m-1;
            }
        }
        // cout << abs((((double)ans+1)*(double)hot + (double)ans*(double)c)/(2*(double)ans+1) - (double)t) << " " <<  abs((((double)ans+2)*(double)hot + ((double)ans+1)*c)/(2*((double)ans+1)+1) - (double)t) << " ";
        if (ans == 1e9) cout << 2 << endl;
        else if (abs((((double)ans+1)*(double)hot + (double)ans*(double)c)/(2*(double)ans+1) - (double)t) <= abs((((double)ans+2)*(double)hot + ((double)ans+1)*c)/(2*((double)ans+1)+1) - (double)t)) cout << ans * 2 + 1 << endl;
        else cout << ans * 2 + 3 << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}