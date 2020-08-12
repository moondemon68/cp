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
    cin >>tc;
    while(tc--) {
        int n;
        cin >> n;
        int x = n-6-10-14;
        int y = n-6-10-15;
        int z = n-10-14-15;
        if (x != 6 && x != 10 && x != 14 && x > 0) {
            cout << "YES" << endl;
            cout << "6 10 14 " << x << endl;
        } else if (y != 6 && y != 10 && y != 15 && y > 0) {
            cout << "YES" << endl;
            cout << "6 10 15 " << y << endl;
        } else if (z != 14 && z != 10 && z != 15 && z > 0) {
            cout << "YES" << endl;
            cout << "10 14 15 " << z << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}