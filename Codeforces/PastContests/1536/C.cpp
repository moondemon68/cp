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
        string s;
        cin >> s;
        map<pii, int> m;
        int d = 0, k = 0;
        for (int i=0;i<s.size();i++) {
            if (s[i] == 'D') d++; else k++;
            if (d != 0 && k != 0) m[{d/__gcd(d, k), k/__gcd(d, k)}]++;
            // cout << d << " " << k << " " << m[{d/__gcd(d, k), k/__gcd(d, k)}] << endl;
            if (d == 0) cout << k;
            else if (k == 0) cout << d;
            else if (__gcd(d, k) == 1) cout << 1;
            else {
                // int x = __gcd(d, k);
                // vector<int> fac;
                // for (int j=1;j*j<=x;j++) {
                //     if (x % j == 0){
                //         fac.pb(j);
                //         if (j * j != x) fac.pb(x/j);
                //     }
                // }
                // sort(fac.begin(), fac.end());
                // reverse(fac.begin(), fac.end());
                // for (auto p : fac) {
                //     if (m[{d/__gcd(d, k), k/__gcd(d, k)}] == p) {
                //         cout << p;
                //         break;
                //     }
                // }
                cout << m[{d/__gcd(d, k), k/__gcd(d, k)}];
            }
            cout << " ";
        }
        cout << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
// 1
// 15
// KKKDDKDKKKKDDDD
// 1 2 3 1 1 1 1 1  1 1  1 2 1 

// KKKDDKDKK