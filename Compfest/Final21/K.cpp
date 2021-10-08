#pragma GCC target ("avx2")
#pragma GCC optimization ("O2")
#pragma GCC optimization ("unroll-loops")
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

const int N = 3e4 + 5;
int n, k;
// long long dp[N + 5][N + 5];
// long long pd[N + 5][N + 5];
bitset<N*N+5> dp;
unordered_map<int, LL> pd;
// LL pd[N*N+5];

int code(int r, int c) {
    return r * N + c;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> k;
  clock_t start = clock();

  stack<pii> s;
  s.push({k, k});
  vector<int> kena;
  dp[code(k, k)] = 1;
  int x = 0;
  while (!s.empty()) {
      x++;
      pii cur = s.top();
      int tmp = code(cur.fi, cur.se);
      kena.pb(tmp);
      s.pop();
      int x = code(cur.fi+cur.se-1, cur.se-1);
      int y = code(cur.fi+cur.se, cur.se);
      int z = code(cur.fi+cur.se+1, cur.se+1);
      if (cur.fi+cur.se-1 <= n && cur.se-1 >= 1 && dp[x] == 0) {
        s.push({cur.fi+cur.se-1, cur.se-1});
        dp[x] = dp[tmp];
      }
      if (cur.fi+cur.se <= n && cur.se >= 1 && dp[y] == 0) {
        s.push({cur.fi+cur.se, cur.se});
        dp[y] = dp[tmp];
      }
      if (cur.fi+cur.se+1 <= n && cur.se+1 >= 1 && dp[z] == 0) {
        s.push({cur.fi+cur.se+1, cur.se+1});
        dp[z] = dp[tmp];
      }
  }
  sort(kena.begin(), kena.end());

    pd[code(k, k)] = 1;
    for (int g = 0; g < kena.size(); g++) {
        int x = kena[g];
        if (g > 0 && kena[g] == kena[g-1]) continue;
        int i = x / N, j = x % N;
        int c = code(i, j), d = code(i-j, j);
        if (i >= j) {
            // if (dp[d-1]) pd[c] += pd[d-1];
            // if (dp[d]) pd[c] += pd[d];
            // if (dp[d+1]) pd[c] += pd[d+1];
            pd[c] += pd[d-1] + pd[d] + pd[d+1];
            pd[c] %= MOD;
        }
    }

//   for(int i = 0; i <= n; i++) {
//     for(int j = 1; j <= n; j++) {
//       cout << pd[i][j] << " ";
//     }
//     cout << '\n';
//   }

    // int cnt = 0;
    // for(int i = 0; i <= n; i++) {
    //     for(int j = 1; j <= n; j++) {
    //         if (dp[i][j] > 0) {
    //             cnt++;
    //         }
    //     }
    // }
    // cout << cnt << endl;
    // cout << "visits: " << kena.size() << " " << x << endl;
  long long sum = 0;
  for(int i = 1; i <= n; i++) {
    sum = (sum + pd[code(n, i)]) % MOD;
  }
  cout << sum << '\n';
  cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
  return 0;
}