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
        LL a,b,x,y,n;
        cin >> a >> b >> x >> y >> n;
        if (a < b) {
            swap(a, b);
            swap(x, y);
        }
        LL ans = a * b;

        // abisin di b 
        LL na = a, nb = b, nx = x, ny = y, nn = n;
        LL moveb = min(nb-ny, nn);
        nb -= moveb;
        nn -= moveb;
        if (nn > 0) {
            LL movea = min(na-nx, nn);
            na -= movea;
            nn -= movea;
        }
        ans = min(ans , na * nb);

        // abisin di a
        na = a, nb = b, nx = x, ny = y, nn = n;
        LL movea = min(na-nx, nn);
        na -= movea;
        nn -= movea;
        if (nn > 0) {
            LL moveb = min(nb-ny, nn);
            nb -= moveb;
            nn -= moveb;
        }
        ans = min(ans, na * nb);

        cout << ans << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}