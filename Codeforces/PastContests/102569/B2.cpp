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
    int n, t;
    cin >> n >> t;
    vll p[2];
    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        if (x >= 0) p[0].pb(x);
        else p[1].pb(-x);
    }
    for (int i = 0; i < 2; i++) sort(p[i].begin(), p[i].end());
    int ans = 0;
    for (int c = 0; c < 2; c++) {
        int l = 1 ^ c;
        for (int i = 0; i < sz(p[c]); i++) {
            if (p[c][i] > t) break;
            ans = max(ans, i + 1);
            if (sz(p[l]) == 0) {
                continue;
            }
            int ct = t - p[c][i];
            int lo = 0, hi = sz(p[l]) - 1, mid, best = -1;
            while (lo <= hi) {
                mid = (lo + hi) / 2;
                if (p[l][mid] <= ct) {
                    best = mid;
                    lo = mid + 1;
                } else {
                    hi = mid - 1;
                }
            }
            if (best != -1) {
                ans = max(ans, i + 1 + best + 1);
            }
        }
    }
    cout << ans << '\n';
    return 0;
}