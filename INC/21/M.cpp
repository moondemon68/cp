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
    LL k, s, n;
    cin >> k >> s >> n;
    
    // case 1, semua menang telak
    LL l2 = s * k;
    LL r2 = s * (k-2) + s * k;
    if (l2 <= n && n <= r2) {
        cout << "YES" << endl;
        return 0;
    }

    if (s == 1) {
        LL l = k, r = k + k - 2;
        if (n < l) {
            cout << "NO" << endl;
        } else if (l <= n && n <= r) {
            cout << "YES" << endl;
        } else if (n % 2 == 1) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }
    } else if (k == 2) {
        if (n < s * k) {
            cout << "NO" << endl;
        } else if (n % 2 == 0) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    } else {
        if (n >= s * k) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}