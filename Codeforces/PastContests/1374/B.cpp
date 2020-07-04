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
        LL x;
        cin >> x;
        LL m2 = 0, m3 = 0;
        while (x != 1) {
            if (x % 3 == 0) {
                m3++;
                x /= 3;
            } else if (x % 2 == 0) {
                m2++;
                x /= 2;
            } else {
                break;
            }
        }
        if (x != 1 || m2 > m3) cout << -1 << endl;
        else cout << min(m2, m3) + (m3-m2)*2 << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}