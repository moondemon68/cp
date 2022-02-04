#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll ext_gcd(ll m1, ll m2, ll &x, ll &y) {
    if (m2 == 0) {
        x = 1;
        y = 0;
        return m1;
    }
    ll x1, y1;
    ll d = ext_gcd(m2, m1 % m2, x1, y1);
    x = y1;
    y = x1 - y1 * (m1 / m2);
    return d;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ll a, b, m, n;
  cin >> a >> b >> m >> n;
  ll g = __gcd(m, n);
  ll p, q;
  ext_gcd(m/g, n/g, p, q);
//   cout << p << " " << q << endl;
  ll ans = a * n / g * q + b * m / g * p;
  ans %= (m * n / g);
  ans += (m * n / g);
  ans %= (m * n / g);
  cout << ans << '\n';
  return 0;
}