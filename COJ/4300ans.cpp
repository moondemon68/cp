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
    LL ans[]={1, 3, 15, 75, 391, 2065, 11091, 60215, 330003, 1820869, 10103153, 56313047, 315071801, 1768489771, 9953853677, 56158682949, 317505199769, 1798402412539};
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        cout << ans[n] << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}