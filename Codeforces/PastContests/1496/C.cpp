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
        vector<int> m, d;
        for (int i=1;i<=2*n;i++) {
            int x,y;
            cin >> x >> y;
            if (x == 0) m.pb(abs(y));
            if (y == 0) d.pb(abs(x));
        }
        sort(m.begin(), m.end());
        sort(d.begin(), d.end());
        double ans = 0;
        for (int i=0;i<m.size();i++) {
            ans += sqrt((double)m[i]*(double)m[i]+(double)d[i]*(double)d[i]);
        }
        cout << fixed << setprecision(10) << ans << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}