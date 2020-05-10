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
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        int x,y,x1,y1,x2,y2;
        cin >> x >> y >> x1 >> y1 >> x2 >> y2;
        if (x1 == x2 && a + b != 0) {
            cout << "NO" << endl;
        } else if (y1 == y2 && c + d != 0) {
            cout << "NO" << endl;
        } else if (x1 <= x+b-a && x+b-a <= x2 && y1 <= y+d-c && y+d-c <= y2) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}