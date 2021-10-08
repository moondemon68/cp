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
        int n,k;
        cin >> n >> k;
        string s;
        cin >> s;
        s += '*';
        int cnt = 0;
        vector<pii> L;
        bool y = 0;
        int start = 0;
        for (int i=0;i<s.size();i++) {
            if (s[i] == 'W') {
                if (!y) start = i;
                y = 1;
            }
            if (!y) continue;
            if (s[i] != 'L') {
                if (cnt > 0 && s[i] != '*') L.pb({cnt, i-cnt});
                cnt = 0;
            } else {
                cnt++;
            }
        }
        // for (int i=0;i<L.size();i++) cout << L[i].fi << " " << L[i].se << endl;
        // cout << endl;
        sort (L.begin(), L.end());
        for (int i=0;i<L.size();i++) {
            if (k > 0) {
                int x = min(k, L[i].fi);
                for (int j=L[i].se;j<=L[i].se+x-1;j++) {
                    s[j] = 'W';
                    k--;
                }
            }
            if (k == 0) break;
        }
        if (k > 0) {
            for (int i=start-1;i>=0;i--) {
                if (k > 0 && s[i] == 'L') {
                    s[i] = 'W';
                    k--;
                } else break;
            }
            // cout << k << endl;
            for (int i=0;i<s.size();i++) {
                if (k > 0 && s[i] == 'L') {
                    s[i] = 'W';
                    k--;
                }
            }
        }
        // cout << s << k << endl;
        int ans = 0;
        y = 0;
        for (int i=0;i<s.size();i++) {
            if (s[i] == 'W') {
                if (y) ans += 2; else ans++;
                y = 1;
            } else {
                y = 0;
            }
        }
        // cout << s << endl;
        cout << ans << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}