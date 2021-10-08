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
        int n;
        cin >> n;
        bool y = 0;
        for (int i=0;i<=n;i++) {
            for (int j=0;j<=n;j++) {
                if ((n - i * 3 - j * 5) % 7 == 0 && (i * 3 + j * 5) <= n) {
                    y = 1;
                    cout << i << " " << j << " " << (n - i * 3 - j * 5) / 7 << endl;
                    break;
                } else if ((i * 3 + j * 5) > n) break;
            }
            if (y) break;
        }
        if (!y) cout << -1 << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}