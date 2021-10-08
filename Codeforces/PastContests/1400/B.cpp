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
        int p,f;
        cin >> p >> f;
        int cnts, cntw;
        cin >> cnts >> cntw;
        int s,w;
        cin >> s >> w;
        int ans = 0;
        for (int i=0;i<=cnts;i++) {
            int rem = p - i * s;
            if (rem < 0) continue;
            int ptakes = i;
            int ptakew = min(cntw, rem/w);
            for (int ftakes = min(cnts-ptakes, f/s)-10; ftakes <= min(cnts-ptakes, f/s) + 10; ftakes++) {
                int ftakew = min(cntw-ptakew, (f-ftakes * s)/w);
                if (ftakew < 0) continue;
                if (ftakes < 0 || ftakes > cnts-ptakes) continue;
                // cout << ptakes << " " << ptakew << " " << ftakes << " " << ftakew << endl;
                ans = max(ans, ptakes + ptakew + ftakes + ftakew);
            }
        }
        cout << ans << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}