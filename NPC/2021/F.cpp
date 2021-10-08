#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define pii pair<int, int>
#define pll pair<ll, ll>

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  string s, t;
  cin >> s >> t;
  int ans = s.size() + t.size();
  for (int sw = 0; sw < 2; sw++) {
    int last = -1;
    int cur = 0;
    for (int i = 0; i < (int)s.size(); i++) {
      if (s[i] == t[last + 1]) {
        last++;
        if (last == t.size() - 1) {
          ans = min(ans, (int)max(s.size(), t.size()));
        }
      } else {
        last = -1;
      }
    }
    ans = min(ans, (int)(s.size() + t.size() - last - 1));
    swap(s, t);
  }
  cout << ans << '\n';
  return 0;
}
/*
abababc
ababc
*/
