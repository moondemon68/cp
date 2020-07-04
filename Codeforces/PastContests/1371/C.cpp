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
        LL a,b,n,m;
        cin >> a >> b >> n >> m;
        if (n+m > a+b) {
            cout << "NO" << endl;
            continue;
        }
        bool y = 0;
        for (int i=1;i<=1000;i++) {
            if (a <= b) {
                if (n <= b) {
                    LL x = min(n, b);
                    n -= x;
                    b -= x;
                }
                if (a <= b && m <= a) {
                    LL x = min(m, a);
                    m -= x;
                    a -= x;
                }
            }
            if (a > b) {
                if (n <= a) {
                    LL x = min(n,a);
                    n -= x;
                    a -= x;
                }
                if (a > b && m <= b) {
                    LL x = min(m, b);
                    m -= x;
                    b -= x;
                }
            }
            if (n == 0 && m == 0) {
                cout << "YES" << endl;
                y = 1;
                break;
            }
        }
        
        // cout << a << " " << b << " " << n << " " << m << endl;
        if (!y) cout << "NO" << endl;
    }

    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}