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
        string t = "";
        for (int i=0;i<s.size();i++) {
            if (s[i] != s[(i+1)%n]) {
                int x = i+1;
                while (t.size() < n) {
                    t += s[x%n];
                    x++;
                }
            }
        }
        if (t == "") {
            cout << (n+2)/3 << endl;
            continue;
        }
        // cout << t << endl;
        int cnt = 1, ans = 0;
        for (int i=0;i<t.size();i++) {
            if (t[i] == t[(i+1)]) {
                cnt++;
            } else {
                // cout << cnt << " ";
                ans += (cnt)/3;
                cnt = 1;
            }
        }
        cout << ans << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}