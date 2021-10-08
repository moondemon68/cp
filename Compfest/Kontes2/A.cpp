#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pb push_back
#define sz(a) (int)(a).size()
#define mp(a, b) make_pair((a), (b))
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;

const ll MOD = 1e9 + 7;
const ll INF = 1e18;
const ll IINF = INT_MAX;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tc;
    cin >> tc;
    while (tc--) {
        double r, s;
        cin >> r >> s;
        double curh = s;
        ll ans = 0;
        while (curh <= r) {
            double width = (r * r) - (curh * curh);
            width = sqrt(width);
            width *= 2;
            ans += (ll)width / (ll)s;
            curh += s;
        }
        cout << ans << '\n';
    }
    return 0;
}