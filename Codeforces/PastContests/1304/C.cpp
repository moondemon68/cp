#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
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
        bool ans = 1;
        int n,m;
        cin >> n >> m;
        pair<int,pii> a[n+5];
        for (int i=1;i<=n;i++) cin >> a[i].fi >> a[i].se.fi >> a[i].se.se;
        a[0].fi = 0;
        int x = m, y = m;
        for (int i=1;i<=n;i++) {
            int d = a[i].fi - a[i-1].fi;
            x = x-d;
            y = y+d;
            // cout << "BEFORE: " << x << " " << y << endl;
            int tx = a[i].se.fi, ty = a[i].se.se;
            if (x >= tx && y <= ty) {
                
            } else if (x >= tx && y > ty) {
                y = ty;
            } else if (x < tx && y <= ty) {
                x = tx;
            } else {
                x = tx;
                y = ty;
            }
            // cout << "AFTER: " << x << " " << y << endl;
            if (x > y) {
                ans = 0;
                break;
            }
        }
        if (ans) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}