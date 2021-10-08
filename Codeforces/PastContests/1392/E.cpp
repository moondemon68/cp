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
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);
    LL p[55];
    p[0] = 1;
    for (LL i=1;i<=50;i++) p[i] = 2 * p[i-1];
    LL n;
    cin >> n;
    for (LL i=0;i<n;i++) {
        if (i % 2 == 0) {
            for (LL j=0;j<n;j++) cout << p[i+j] << " ";
        } else {
            for (LL j=0;j<n;j++) cout << 0 << " ";
        }
        cout << endl;
    }
    LL q;
    cin >> q;
    while (q--) {
        LL x;
        cin >> x;
        vector<LL> v;
        while (v.size() < 2*n) {
            v.pb(x%2);
            x /= 2;
        }
        // for (int i=0;i<v.size();i++) cout << v[i];
        // cout << endl;
        LL px = 1, py = 1, i = 0;
        cout << px << " " << py << endl;
        for (LL i=0;i<v.size()-2;i++) {
            if (v[i] == v[i+1]) {
                py++;
                cout << px << " " << py << endl;
            } else {
                px++;
                cout << px << " " << py << endl;
            }
        }
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}