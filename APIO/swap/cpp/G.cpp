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
        int x,y;
        cin >> x >> y;
        int l=0,d=0,r=0,u=0;
        for (int i=0;i<s.size();i++) {
            if (s[i] == 'L') l++;
            if (s[i] == 'R') r++;
            if (s[i] == 'U') u++;
            if (s[i] == 'D') d++;
        }
        int q;
        cin >> q;
        while (q--) {
            int xx, yy;
            cin >> xx >> yy;
            int dx = xx-x, dy = yy-y;
            int ans = 0;
            if (dx > 0) {
                if (r >= dx) ans += dx;
                else {
                    cout << "NO" << "\n";
                    continue;
                }
            }
            if (dy > 0) {
                if (u >= dy) ans += dy;
                else {
                    cout << "NO" << "\n";
                    continue;
                }
            }

            if (dx < 0) {
                if (l >= -dx) ans += -dx;
                else {
                    cout << "NO" << "\n";
                    continue;
                }
            }
            if (dy < 0) {
                if (d >= -dy) ans += -dy;
                else {
                    cout << "NO" << "\n";
                    continue;
                }
            }
            cout << "YES" << " " << ans << "\n";
        }
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << "\n";
    return 0;
}