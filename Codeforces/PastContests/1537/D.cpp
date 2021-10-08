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
        LL n;
        cin >> n;
        if (n <= 3 || n % 2 == 1) cout << "Bob";
        else {
            LL p = 1, cnt = 0;
            while (p * 2 <= n) {
                p *= 2;
                cnt++;
            }
            if (p == n) {
                if (cnt % 2 == 0) cout << "Alice";
                else cout << "Bob";
            } else {
                cout << "Alice";
            }
        }
        cout << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}