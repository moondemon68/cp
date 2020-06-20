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
        // vector<int> v;
        // while (n) {
        //     v.pb(n%2);
        //     n/=2;
        // }
        // for (int i=0;i<v.size();i++) cout << v[i];
        // cout << endl;
        if (n == 1) {
            cout << "FastestFinger";
        } else if (n == 2) {
            cout << "Ashishgup";
        } else if (n % 2 == 1) {
            cout << "Ashishgup";
        } else {
            int cnt = 0;
            set<int> s;
            map<int,int> m;
            for (int i=2;i<n;i++) {
                if (i >= 100000) break;
                while (n%i == 0) {
                    if (i%2 == 1) {
                        s.insert(i);
                        m[i]++;
                    } else {
                        cnt++;
                    }
                    n /= i;
                }
            }
            int x = 0;
            for (auto p : s) {
                x += m[p];
            }
            if (n > 1) x++;
            // cout << x <<  " " << cnt  << endl;
            if ((x == 0 && cnt > 1) || (x == 1 && cnt == 1)) cout << "FastestFinger";
            else cout << "Ashishgup";
        }
        cout << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}