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
        int mini = INT_MAX, maxi = 0;
        for (int i=1;i<=n;i++) {
            mini = min(mini, a[i]);
            maxi = max(maxi, a[i]);
        }
        if (mini == maxi) cout << -1 << endl;
        else {
            vector<int> v;
            for (int i=1;i<=n;i++) {
                if (a[i] == maxi) v.pb(i);
            }
            if (v.size() == 1) cout << v[0] << endl;
            else {
                bool y = 0;
                for (int i=0;i<v.size()-1;i++) {
                    if (v[i+1] - v[i] != 1) {
                        cout << v[i] << endl;
                        y = 1;
                        break;
                    }
                }
                if (!y) {
                    if (v[0] != 1) cout << v[0] << endl;
                    else if (v[v.size()-1] != n) cout << v[v.size()-1] << endl;
                }
            }
        }
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}