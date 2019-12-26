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
    ifstream cin("2.in");
    ofstream cout("2.out");
    long long ans = 0, x = 0;
    while (cin >> x) {
        while (x >= 6) {
            ans += x / 3 - 2;
            x /= 3;
            x -= 2;
        }
    }
    cout << ans << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}