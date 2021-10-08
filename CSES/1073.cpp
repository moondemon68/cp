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

vector<int> v;

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for (int i=1;i<=n;i++) {
        int x;
        cin >> x;
        if (v.empty()) {
            v.pb(x);
        } else {

            int l = 0, r = v.size()-1, p = -1;
            while (l <= r) {
                int m = (l+r)/2;
                if (v[m] > x) {
                    r = m-1;
                    p = m;
                } else {
                    l = m+1;
                }
            }
            if (p == -1) {
                v.pb(x);
            } else {
                v[p] = x;
            }
            // sort (v.begin(), v.end());
        }
    }
    // for (auto x : v) cout << x << " ";
    cout << v.size() << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}