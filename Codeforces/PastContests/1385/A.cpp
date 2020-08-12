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
        int a[3];
        cin >> a[0] >> a[1] >> a[2];
        sort (a,a+3);
        if (a[0] < a[1] && a[1] < a[2]) {
            cout << "NO" << endl;
        } else if (a[0] < a[1] && a[1] == a[2]) {
            cout << "YES" << endl;
            cout << a[1] << " " << a[0] << " " << 1 << endl;
        } else if (a[0] == a[1] && a[1] == a[2]) {
            cout << "YES" << endl;
            cout << a[0] << " " << a[1] << " " << a[2] << endl;
        } else if (a[0] == a[1] && a[1] < a[2]) {
            cout << "NO" << endl;
        }
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}