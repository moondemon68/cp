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
        string s;
        cin >> s;
        int cur = s[0], cnt = 1;
        vector<pii> v;
        s += '*';
        for (int i=1;i<s.size();i++) {
            if (s[i] != cur) {
                v.pb({cur - '0', cnt});
                cur = s[i];
                cnt = 1;
            } else {
                cnt++;
            }
        }
        int ans = INT_MAX;
        for (int i=1;i<v.size()-1;i++) {
            if (v[i].fi != v[i+1].fi && v[i].fi != v[i-1].fi && v[i-1].fi != v[i+1].fi) ans = min(ans, v[i].se);
        }
        if (ans == INT_MAX) cout << 0 << endl;
        else cout << ans + 2 << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}