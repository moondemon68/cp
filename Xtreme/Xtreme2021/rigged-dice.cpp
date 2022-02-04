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
        int a[7], b[7];
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        int ca = 0, cb = 0;
        bool y = 0;
        for (int i=1;i<=n;i++) {
            int ga, gb;
            cin >> ga >> gb;
            ca += ga;
            cb += gb;
            if (y) {
                a[ga]++;
                b[gb]++;
            } else {
                b[ga]++;
                a[gb]++;
            }
            if (ca != cb) {
                y = !y;
            }
        }
        int mina = 1e9, minb = 1e9, maxa = 0, maxb = 0, tmp;
        for (int i=1;i<=6;i++) {
            maxa = max(maxa, a[i]);
            maxb = max(maxb, b[i]);
            mina = min(mina, a[i]);
            minb = min(minb, b[i]);
        }
        if ((maxa - mina) >= (maxa - minb)) {
            cout << 1 << endl;
        } else {
            cout << 2 << endl;
        }
        // for (int i=1;i<=6;i++) {
        //     cout << a[i] << " " << b[i] << endl;
        // }
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}