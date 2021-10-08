#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define INF 1234567890
#define pii pair<LL,LL>
#define LL long long

using namespace std;

const int N = 3e4 + 5;
int n, k;
// long long dp[N + 5][N + 5];
// long long pd[N + 5][N + 5];
unordered_map<LL, LL> dp[N+5];
unordered_map<LL, LL> pd[N+5];

LL code(LL r, LL c) {
    return r * N + c;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> k;

  stack<pii> s;
  s.push({k, k});
  set<pii> kena;
  dp[k][k] = 1;
  int x = 0;
  while (!s.empty()) {
      x++;
      pii cur = s.top();
      kena.insert(cur);
      s.pop();
      if (cur.fi+cur.se-1 <= n && cur.se-1 >= 1 && dp[cur.fi+cur.se-1][cur.se-1] == 0) {
        s.push({cur.fi+cur.se-1, cur.se-1});
        dp[cur.fi+cur.se-1][cur.se-1] += dp[cur.fi][cur.se];
      }
      if (cur.fi+cur.se <= n && cur.se >= 1 && dp[cur.fi+cur.se][cur.se] == 0) {
        s.push({cur.fi+cur.se, cur.se});
        dp[cur.fi+cur.se][cur.se] += dp[cur.fi][cur.se];
      }
      if (cur.fi+cur.se+1 <= n && cur.se+1 >= 1 && dp[cur.fi+cur.se+1][cur.se+1] == 0) {
        s.push({cur.fi+cur.se+1, cur.se+1});
        dp[cur.fi+cur.se+1][cur.se+1] += dp[cur.fi][cur.se];
      }
  }

    pd[k][k] = 1;
    for (auto x : kena) {
        int i = x.fi, j = x.se;
        if (i >= j) {
            pd[i][j] += pd[i - j][j - 1];
            pd[i][j] += pd[i - j][j];
            pd[i][j] += pd[i - j][j + 1];
            pd[i][j] %= MOD;
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
    // cout << "visits: " << x << endl;
  long long sum = 0;
  for(int i = 1; i <= n; i++) {
    sum = (sum + pd[n][i]) % MOD;
  }
  cout << sum << '\n';
  
  return 0;
}