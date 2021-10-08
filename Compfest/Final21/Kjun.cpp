#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 5;
const long long MOD = 1e9 + 7;
int n, k;
long long dp[N + 5][N + 5];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> k;
  dp[k][k] = 1;
  for(int i = k + 1; i <= n; i++) {
    for(int j = 1; j <= n; j++) {

      for(int m = -1; m <= 1; m++) {
        int g = j + m;
        if(g >= 1 && g <= n && i - (g - m) >= 0 && i - (g - m) <= n) {
          dp[i][j] = (dp[i][j] + dp[i - (g - m)][g]) % MOD;
        }
      }
    }
  }

//   for(int i = 0; i <= n; i++) {
//     for(int j = 1; j <= n; j++) {
//       cout << dp[i][j] << " ";
//     }
//     cout << '\n';
//   }

  int cnt = 0;
    for(int i = 0; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if (dp[i][j] > 0) {
                cnt++;
            }
        }
    }
    cout << cnt << endl;

  long long sum = 0;
  for(int i = 1; i <= n; i++) {
    sum = (sum + dp[n][i]) % MOD;
  }
  cout << sum << '\n';
  
  return 0;
}