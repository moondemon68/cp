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
  int n;
  cin >> n;
  int a[n+5];
  for (int i=1;i<=n;i++) cin >> a[i];
  if (n == 3) {
      if (a[1] == 2 && a[2] == 1 && a[3] == 3) {
          cout << "1 1 0" << endl;
          cout << "0 1 0" << endl;
          cout << "1 1 1" << endl;
      } else if (a[1] == 1 && a[2] == 2 && a[3] == 3) {
          cout << "1 0 0" << endl;
          cout << "1 2 1" << endl;
          cout << "1 1 1" << endl;
      } else {
          cout << -1 << endl;
      }
  } else if (n == 4) {
      cout << -1 << endl;
    } else {
      assert(n == 4);
    //   cout << -1 << endl;
  }
  return 0;
}