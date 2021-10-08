#include <bits/stdc++.h>
using namespace std;
#define pb push_back
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tc;
    cin >> tc;
    while (tc--) {
        ll n;
        cin >> n;
        ll ans = 0;
        bool turn = true;
        while (n > 0) {
            ll add;
            if (n & 1) add = 1;
            else add = n / 2;
            if (turn) {
                ans += add;
            }
            n -= add;
            turn = !turn;
        }
        cout << ans << '\n';
    }
    return 0;
}