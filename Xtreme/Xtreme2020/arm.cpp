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
        int c,h,o;
        cin >> c >> h >> o;
        int ans = c + h + o;
        for (int x=0;x<=500;x++) {
            for (int y=0;y<500;y++) {
                for (int z=0;z<=500;z++) {
                    int nc = 0, nh = 0, no = 0;
                    nc += y + 6 * z;
                    nh += 2 * x + 12 * z;
                    no += x + 2 * y + 6 * z;
                    ans = min(ans, abs(c-nc) + abs(h-nh) + abs(o-no));
                }
            }
        }
        cout << ans << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}