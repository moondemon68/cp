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
        string ans = "";
        int p = 0, ss = 0, r = 0;
        for (int i=0;i<s.size();i++) {
            if (s[i] == 'R') p++;
            if (s[i] == 'P') ss++;
            if (s[i] == 'S') r++;
        }
        for (int i=0;i<s.size();i++) {
            if (p >= ss && p >= r) {
                ans += 'P';
            } else if (ss >= p && ss >= r) {
                ans += 'S';
            } else {
                ans += 'R';
            }
        }
        cout << ans << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}