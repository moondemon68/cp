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
        int a[n+5];
        for (int i=1;i<=n;i++) cin >> a[i];
        int cnt = 0;
        vector<int> v;
        for (int i=1;i<=n;i++) {
            if (a[i] != i) {
                v.pb(i);
                cnt++;
            }
        }
        if (cnt == 0) cout << 0 << endl;
        else {
            bool y = 1;
            for (int i=0;i<v.size()-1;i++) {
                if (v[i] != v[i+1] - 1) y = 0;
            }
            if (y) cout << 1 << endl;
            else cout << 2 << endl;
        }
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}