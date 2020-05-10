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
    int x;
    cin >> x;
    vector<int> v;
    while (v.size() != 6) {
        v.pb(x%2);
        x/=2;
    }
    // reverse(v.begin(), v.end());
    int ans = 0;
    for (auto x : v) cout << x;
    cout << endl;
    if (v[0] == 1) ans += (1 << 1);
    if (v[1] == 1) ans += (1 << 4);
    if (v[2] == 1) ans += (1 << 2);
    if (v[3] == 1) ans += (1 << 3);
    if (v[4] == 1) ans += (1 << 5);
    if (v[5] == 1) ans += (1 << 0);
    cout << ans << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}