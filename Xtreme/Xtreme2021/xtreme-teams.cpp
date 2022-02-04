#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define pii pair<int, int>
#define pll pair<ll, ll>

void dnc(vector<int>& maskPair, int l, int r) {
  if (l == r) {
    return;
  }
  int mid = (l + r) / 2;
  int len = (r - l + 1) / 2;
  dnc(maskPair, l, mid);
  dnc(maskPair, mid + 1, r);
  for (int i = l; i <= mid; i++) {
    maskPair[i] += maskPair[i + len];
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int tc;
  cin >> tc;
  while (tc--) {
    int n, m;
    cin >> n >> m;
    vector<int> ar(n);
    int semua = (1 << m) - 1;
    for (int i = 0; i < n; i++) {
      string s;
      cin >> s;
      int val = 0;
      for (int j = 0; j < (int)s.size(); j++) {
        if (s[j] == 'y') {
          val += 1 << j;
        }
      }
      ar[i] = val;
    }
    vector<vector<int>> cnt(n+1, vector<int>(semua+1));
    vector<int> maskPair(semua + 1);
    int filled = 0;
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        int val = ar[i] | ar[j];
        maskPair[val]++;
        cnt[i][val] += 2;
        if (val == semua) {
          filled++;
        }
      }
    }

    // for (int i = 0; i < n; i++) {
    //   cout << i << ' ' << bitset<18>( ar[i] ).to_string() << '\n';
    // }

    // for (int mask = 0; mask < (1 << m); mask++) {
    //   cout << bitset<18>( mask ).to_string() << ' ' << maskPair[mask] << '\n';
    // }

    dnc(maskPair, 0, semua);

    // cout << "after count" << '\n';
    // for (int mask = 0; mask < (1 << m); mask++) {
    //   cout << bitset<18>( mask ).to_string() << ' ' << maskPair[mask] << '\n';
    // }    

    ll ans = 0;
    for (int i = 0; i < n; i++) {
      int exc = semua - ar[i];
      ans += maskPair[exc];
    }
    int kurang = 0;
    for (int i=0;i<n;i++) {
        for (int j=0;j<=semua;j++) {
            if ((j | ar[i]) == semua) {
                kurang += cnt[i][j];
                
                // cout << cnt[i][j];
            }
        }
    }
    ans -= kurang;
    ans /= 3;
    cout << kurang << ' ';
    cout << ans << '\n';
  }
  return 0;
}