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
        cout << "? 1" << endl;
        int x;
        cin >> x;
        int l = 1, h = n, ans = 0;
        while (l <= h) {
            int m = (l+h)/2;
            cout << "? " << m << endl;
            cin >> x;
            if (x == 1) {
                h = m-1;
                ans = m;
            } else {
                l = m+1;
            }
            cout << "? " << 1 << endl;
            cin >> x;
        }
        if (ans == 0) cout << "= " << n << endl;
        else cout << "= " << ans-1 << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}