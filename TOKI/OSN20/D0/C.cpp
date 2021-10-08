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
    int k,n;
    cin >> k >> n;
    if (k == 1) {
        int x;
        cin >> x;
        while (x) {
            int p,q;
            if (x <= n) {
                cout << 1 << " " << x << endl;
                cin >> p >> q;
                return 0;
            } else if (x % (n+1) == 0) {
                cout << 1 << " " << 1 << endl;
                x--;
                cin >> p >> q;
                if (p == -1) break;
                x -= q;
            } else {
                cout << 1 << " " << (x%(n+1)) << endl;
                x -= (x%(n+1));
                cin >> p >> q;
                if (p == -1) break;
                x -= q;
            }
        }
    } else {

    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}