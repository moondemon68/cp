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
        LL r,g,b,w;
        cin >> r >> g >> b >> w;
        LL cnt = 0;
        if (r%2 == 1) cnt++;
        if (g%2 == 1) cnt++;
        if (b%2 == 1) cnt++;
        if (w%2 == 1) cnt++;
        if (cnt == 0 || cnt == 1) {
            cout << "Yes" << endl;
            continue;
        }
        LL x = min(r,min(g,b));
        if (x > 1) x = 1;
        w += 3*x;
        r -= x;
        g -= x; 
        b -= x;
        cnt = 0;
        if (r%2 == 1) cnt++;
        if (g%2 == 1) cnt++;
        if (b%2 == 1) cnt++;
        if (w%2 == 1) cnt++;
        if (cnt == 0 || cnt == 1) {
            cout << "Yes" << endl;
            continue;
        }
        cout << "No" << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}